/* server_tcp.c */
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

pthread_mutex_t file_mutex;

int send_list(int sAccept)
{
	FILE *fp = NULL;
	char end = -1;
	ssize_t ret = 0;
	char buf[2048];

	if(recv(sAccept,buf,2048,0) <= 0)
        {
            printf("receive() failure!\n");
            return -1;
        }
        else
        {
		pthread_mutex_lock(&file_mutex);
		fp = fopen(buf,"r");
		if(fp == NULL)
		{
			printf("File not exist\n");
			send(sAccept,"File not exist",15,0);
			close(sAccept);
			return -1;
		}
        }
	send(sAccept,"File open",10,0);
	while(fgets(buf,2048,fp) != NULL)
	{

		if((ret=send(sAccept,buf,strlen(buf)+1,0)) <= 0)
		{
			printf("Send failure\n");
			return -1;
		}
		if(recv(sAccept,buf,1,0) <= 0)
       		{
        	    	printf("reveive() failure!\n");
            		break;
        	}
		while(buf[0] != -2)
		{
			if(recv(sAccept,buf,1,0) <= 0)
       			{
        	    		printf("reveive() failure!\n");
            			break;
        		}
		}
		
		memset(buf,'\0',2048);
	}
	send(sAccept,&end,1,0);
	fclose(fp);
	pthread_mutex_unlock(&file_mutex);
	return 0;
}
void *p_udp(void)
{
	int u_port = DEFAULT_PORT;
	int u_socket;
	int len;
	int ret;
	char buf[1024];
	struct sockaddr_in ser;
	struct sockaddr_in cli;
	FILE *fp;

	u_socket = socket(AF_INET,SOCK_DGRAM,0);
	if(u_socket < 0)
	{
		printf("socket() failure\n");
		return NULL;
	}
	ser.sin_family = AF_INET;
        ser.sin_port = htons(u_port);
        ser.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(u_socket, (struct sockaddr*)&ser, sizeof(ser)) < 0)
        {
                printf("bind() failure!\n");
                return NULL;
        }
	
	len = sizeof(cli);
	memset(buf, 0, sizeof(buf));

	while(1)
	{
		ret = recvfrom(u_socket, buf, 40, 0, (struct sockaddr*)&cli, (unsigned int*)&len);	
		if((ret < 0)||(ret == 0))
       		{
                	printf("recvfrom() failure!\n");
           		continue;
        	}
		if(strncmp(buf,"version",7) == 0)
		{			
			pthread_mutex_lock(&file_mutex);
			fp = fopen("movielist.txt","r");
			if(fp == NULL)
			{
				printf("Open file failure\n");
				continue;
			}
			fgets(buf,1024,fp);
			fgets(buf,1024,fp);
			buf[strlen(buf)-1] = '\0';
			fclose(fp);
			pthread_mutex_unlock(&file_mutex);
		}
		else
		{
			continue;
		}
		ret = sendto(u_socket, &buf[9], sizeof(buf)-9, 0, (struct sockaddr*)&cli, sizeof(cli));
		if((ret < 0)||(ret == 0))
       		 {
            		printf("sendto() failure!\n");
          		continue;
       		 }
	}
}

int main(int argc, char** argv)
{
    int sPort = DEFAULT_PORT;
    int sListen = 0;
    int sAccept = 0;
    unsigned int sLen = 0;
    struct sockaddr_in ser;
    struct sockaddr_in cli;
    char buf[10];
    int ret=0;
    
    pthread_mutex_init(&file_mutex,NULL);	

    pthread_t thread_id;
    pthread_create(&thread_id,NULL,(void *)p_udp,NULL);

    printf("Server waiting...\n");
   
    sListen = socket(AF_INET, SOCK_STREAM, 0);
    if(sListen < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    ser.sin_family = AF_INET;
    ser.sin_port = htons(sPort);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
   
    if(bind(sListen, (struct sockaddr*)&ser, sizeof(ser)) < 0)
    {
        printf("bind() failure!\n");       
        return -1;
    }
   
    if(listen(sListen, 5) < 0)
    {
        printf("listen() failure!\n");        
        return -1;
    }
   
    sLen = sizeof(cli);

    while(1)
    {
	printf("Server waiting for clieng connecting...\n");
        sAccept = accept(sListen, (struct sockaddr*)&cli, (unsigned int*)&sLen);
        if(sAccept < 0)
        {
            printf("accept() failure!\n");             
            break;
        }
       
        printf("accept() client IP: [%s]\n", (char*)inet_ntoa(cli.sin_addr));
        printf("accept() client PORT: [%d]\n", ntohs(cli.sin_port));
       
        
        send_list(sAccept);
	while(1)
	{
		ret=recv(sAccept,buf,10,0);
		if( ret< 0)
        	{
            		printf("receive() failure!\n");
            		continue;
        	}
		if(ret == 0)
		{
			printf("Client is close\n");
			break;
		}
		if(strncmp(buf,"receive",7) == 0)
		send_list(sAccept);
		else
		continue;
	}
        close(sAccept);
    }
    close(sListen);
    return 0;
}
