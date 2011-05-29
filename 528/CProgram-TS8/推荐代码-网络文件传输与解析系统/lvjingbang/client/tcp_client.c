/* client_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define DEFAULT_PORT 5050
#define QUIT -2 
#define UPDATE -3

pthread_mutex_t file_mutex;
pthread_mutex_t flag_mutex;
int update_flag=0; // if flag == 1 need update

typedef struct movie{
	char name[20];
	char dire[20];
	unsigned year;
	struct movie *next;
}movie_t;

void empty_cache()
{
	char ch;
	while((ch=getchar()) != '\n' && ch != EOF);
}

movie_t *creat_list()
{
	FILE *fp = NULL;
	char buf[1024];
	char version[5];
	int num=0;
	movie_t *cur,*k,*first;

	pthread_mutex_lock(&file_mutex);
	fp = fopen("movielist.txt","r");
	if(fp == NULL)
	{
		printf("Open list_file failure\n");
		return NULL;
	}
	fgets(buf,1024,fp);
	fgets(buf,1024,fp);
	buf[strlen(buf)-1] = '\0';
	strncpy(version,&buf[9],5);
	printf("This version is :%s\n",version);
	fgets(buf,1024,fp);
	while(fgets(buf,1024,fp) != NULL)
	{

		if(buf[0] == '*')
			break;
		cur = (movie_t *)malloc(sizeof(movie_t));
		buf[strlen(buf)-1] = '\0';
		if(strncmp(buf,"Name",4) == 0)
		{
			strcpy(cur->name,&buf[8]);
		}
		fgets(buf,1024,fp);
		buf[strlen(buf)-1] = '\0';
		if(strncmp(buf,"Director",8) == 0)
		{
			strcpy(cur->dire,&buf[12]);
		}
		fgets(buf,1024,fp);
		buf[strlen(buf)-1] = '\0';
		if(strncmp(buf,"Year",4) == 0)
		{
			cur->year = atoi(&buf[8]);
		}
		fgets(buf,1024,fp);

		cur->next= NULL;
		if(num == 0)
		{
			first=cur;
			k = cur;
		}
		else
		{

			k->next = cur;
			k = cur;

		}
		num++;
	}

	/*k=first;
	while(k != NULL)
	{
		printf("name=%s\n",k->name);
		printf("director=%s\n",k->dire);
		printf("year=%d\n\n",k->year);
		k = k->next;
	}*/
	
	fclose(fp);
	pthread_mutex_unlock(&file_mutex);
	return first;
}

int free_list(movie_t *first)
{
	movie_t *current=first,*k=first;
	if(first == NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	while(current->next != NULL)
	{
		current=current->next;
		free(k);
		k=current;
	}
	free(current);
	return 0;
}

int print_list(movie_t head,char *buf,int year)
{
	movie_t *current=head.next,*k=head.next;
	int i=1;
	
	if(current == NULL)
	{
		printf("Not have movie\n");
		return -1;
	}

	if(year == 0)
	{
		if(strncmp(buf,"name",4) == 0)
		{
			i=1;
			printf("The movie name list:\n");
			while(current != NULL)
			{
				printf("%d.%s\n",i,current->name);
				i++;
				current = current->next;
			}
			return 0;
		}
		else if(strncmp(buf,"director",8) == 0)
		{
			i=1;
			printf("The movie director list:\n");
			while(current != NULL)
			{
				k=head.next;
				while(k != current)
				{
					if(strcmp(current->dire,k->dire) == 0)
					{
						current = current->next;
						k = head.next;
						break;
					}
					else
					{
						k = k->next;
					}
				}
				if(current == k)
				{
					printf("%d.%s\n",i,current->dire);
					i++;
					current = current->next;
				}
			}
			return 0;
		}
		else 
		{
			i=0;
			while(current != NULL)
			{
				if(strncmp(buf,current->dire,strlen(buf)) == 0)
				{
					i++;
					printf("%d.%s\n",i,current->name);
					current=current->next;
				}
				else
				{
					current = current->next;
				}
			}
		}
		if(i == 0)
		printf("There have nothing about :%s\n",buf);
	}
	else if(year != 0)
	{
		if(year < 0)
		{
			printf("The year is illogical\n");
			return -1;
		}
		else
		{
			i = 0;
			printf("The movie make in %d year:\n",year);
			while(current != NULL)
			{
				if(current->year == year)
				{
					printf("%d.%s\n",i,current->name);
					i++;
					current = current->next;
				}
				else
				{
					current = current->next;
				}
			}
		}
		if(i == 0)
		{
			printf("There is no movie make in %d\n",year);
		}
		
	}
	return 0;
}
int anal_list()
{
	int year=-1;
	char buf[40];
	movie_t head;

	head.next = creat_list();
	if(head.next == NULL)
	{
		printf("Creat list failure\n");
		return -1;
	}
	while(1)
	{
		printf("*****************************************************************************\n");
		printf("Please input the movie [name] or [director] or [year] or [name of director]:\n");
		printf("[update] is check wether need update\n");
		printf("(Press 'q' quit,)\n");
		//fgets(buf,40,stdin);
		//buf[strlen(buf)-1] = '\0';
		scanf("%s",buf);
		empty_cache();
		if(strcmp(buf,"q") == 0)
		{
			free_list(head.next);
			return QUIT;
		}
		if(strcmp(buf,"update") == 0)
		{
			pthread_mutex_lock(&flag_mutex);
			if(update_flag == 1)
			{
				printf("Movie list already update,prepare download\n");
				pthread_mutex_unlock(&flag_mutex);
				free_list(head.next);
				return UPDATE;
			}
			else
			{
				pthread_mutex_unlock(&flag_mutex);
				printf("The movie list is latest\n");
				continue;
			}
		}
		year = atoi(buf);
		print_list(head,buf,year);
	}
	free_list(head.next);
	return 0;
}

int receive_list(int cClient)
{
	FILE *fp=NULL;
	char cbuf[2048];
	char name[20];	
	ssize_t ret;
	char flag=-2;	

	//printf("Please input file name:");
	//fgets(cbuf,2048,stdin);
	//cbuf[strlen(cbuf)-1]='\0';
	memset(cbuf, 0, sizeof(cbuf));
	strncpy(cbuf,"movielist.txt",14);
    	strncpy(name,cbuf,strlen(cbuf)+1);

    	if(send(cClient,cbuf,strlen(cbuf)+1,0) <= 0) 
    	{
		printf("Send name failure\n");
		return -1;
    	}   
    	if(recv(cClient,cbuf,20,0) <= 0)    
    	{
		printf("Receive failure\n");
		return -1;
    	}

    	if(strncmp(cbuf,"File not exist",14) == 0)
    	{
		printf("File not exist\n");
		return -1;
    	}
    	if(strncmp(cbuf,"File open",9) == 0)
	printf("File exist...\n");

    	pthread_mutex_lock(&file_mutex);
    	fp = fopen(name,"w");
    	if(fp == NULL)
    	{
		printf("Open file failure\n");
		return -1;
    	}
   	while(1)
    	{
		if((ret=recv(cClient,cbuf,2048,0)) <= 0)    
        	{
	    		printf("Receive failure\n");
	    		perror("receive:");
	    		return -1;
        	}   
  
		if(send(cClient,&flag,1,0) <= 0) 

        	{
			printf("Send name failure\n");
			return -1;
        	}   	

		if(cbuf[0] == -1)
		{
			printf("List transport OK!\n");
			break;
		}
		if(fputs(cbuf,fp) == EOF)
        	{
	    		printf("fputs failure\n");
	    		return -1;
        	}
    	}
    	fclose(fp);
    	pthread_mutex_unlock(&file_mutex);
	return 0;
}

void *p_udp(char *addr)
{
	int port = DEFAULT_PORT;
	int sock;
	unsigned int len=0;
	int ret=0;
	char buf[1024];
	char version[6];
	struct sockaddr_in cli;
	FILE *fp=NULL;

	memset(buf, 0, sizeof(buf));
	cli.sin_family = AF_INET;
	cli.sin_port = htons(port);
        cli.sin_addr.s_addr = inet_addr(addr);

	sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock < 0)
        {
    	    printf("socket() failure!\n");
      	    return NULL;
   	}

	while(1)
	{
		sleep(2);
		strncpy(buf,"version",8);
		len = sizeof(cli);
		ret = sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&cli, len);
    		if((ret < 0)||(ret == 0))
    		{
    		    printf("sendto() failure!\n");
    		    continue;
   		}

		ret = recvfrom(sock, version, sizeof(version), 0, (struct sockaddr*)&cli, (unsigned int*)&len);
    		if((ret < 0)||(ret == 0))
   		{
        		printf("recvfrom() failure!\n");
        		continue;
    		}
		pthread_mutex_lock(&file_mutex);
		fp = fopen("movielist.txt","r");
		if(fp == NULL)
		{
			pthread_mutex_unlock(&file_mutex);
			printf("Open file failure\n");
			continue;
		}
		fgets(buf,1024,fp);
		fgets(buf,1024,fp);
		fclose(fp);
		pthread_mutex_unlock(&file_mutex);
		buf[strlen(buf)-1] = '\0';
		ret = strncmp(version,&buf[9],4);
		if(ret > 0)
		{
			pthread_mutex_lock(&flag_mutex);
			update_flag = 1;
			pthread_mutex_unlock(&flag_mutex);
		}
		else if(ret == 0)
		{
			pthread_mutex_lock(&flag_mutex);
			update_flag = 0;
			pthread_mutex_unlock(&flag_mutex);
		}
	}
}

int main(int argc, char** argv)
{
    	int cPort = DEFAULT_PORT;
    	int cClient = 0;
    	int ret=0;
    	struct sockaddr_in cli;	

    	pthread_t thread_id;
    	pthread_create(&thread_id,NULL,(void *)p_udp,(char *)argv[1]);

    	if(argc < 2)
    	{
        	printf("Uasge: client[server IP address]\n");
        	return -1;
    	}
   
    	pthread_mutex_init(&file_mutex,NULL);
    	pthread_mutex_init(&flag_mutex,NULL);
   
    	cli.sin_family = AF_INET;
    	cli.sin_port = htons(cPort);
    	cli.sin_addr.s_addr = inet_addr(argv[1]);
   
    	cClient = socket(AF_INET, SOCK_STREAM, 0);
    	if(cClient < 0)
    	{
        	printf("socket() failure!\n");
        	return -1;
    	}
   
    	if(connect(cClient, (struct sockaddr*)&cli, sizeof(cli)) < 0)
    	{
       		printf("connect() failure!\n");
       		return -1;
    	}
    	
	receive_list(cClient);
	while(1)
	{
		ret = anal_list();
		if(ret == QUIT)
			break;
		if(ret == UPDATE)
		{
			pthread_mutex_lock(&flag_mutex);
			if(update_flag == 1)
			{
				printf("Update\n");
				if(send(cClient,"receive",8,0) <= 0) 
				{
					printf("Send failure\n");
					pthread_mutex_unlock(&flag_mutex);
					return -1;
				}   
				receive_list(cClient);
				update_flag = 0;
				printf("Update OK!\n");
			}
			pthread_mutex_unlock(&flag_mutex);
		}
	}

    close(cClient);
   
    return 0;
}
