/* client_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050

int flag=0;
/**************************************************************
 search for parse movie list
***************************************************************/
int search(void)
{
        char tbuf[256]={0};
	int n=0;
	char *p=NULL;
	char wbuf[128]={0};
	char kbuf[128]={0};
	char jbuf[128]={0};
	float m=0;
	FILE *fp1=fopen("movielist.txt","r");
	if(!fp1){
		printf("Can't open\n");
		return -1;
	}
	else{
	
	while(1){
	printf("*****************************\n");
	printf("****1.name     list    ******\n");
	printf("****2.derictor list    ******\n");
        printf("****3.list by year     ******\n");
	printf("****4.others           ******\n");
	printf("****5.       Exit      ******\n");
        printf("Please choose:\n");
	scanf("%d",&n);
	switch(n){
	case 1:
		fseek(fp1,0,0);
		 while ( fgets (tbuf, sizeof(tbuf), fp1) != NULL)
    			{      			 
			   p=strstr(tbuf,"Name");
			    if(p){
   				printf("%s \n",p);
			     }
			}
  		break;
	
	case 2:fseek(fp1,0,0);
		while ( fgets (tbuf, sizeof(tbuf), fp1) != NULL)
    			{
      			
			   p=strstr(tbuf,"Director");
			    if(p){
   				printf("%s \n",p);
			     }
			}
  		break;
	case 3: 
		fseek(fp1,0,0);
        	printf("Witch year:");
        	scanf("%s",wbuf);
       		while ( fgets (tbuf, sizeof(tbuf), fp1) !=NULL){
               		 p=strstr(tbuf,wbuf);
			 if(p){						 	
				printf("%s\n",kbuf);
				printf("%s\n",jbuf);
				printf("%s\n",tbuf);
				printf("$$$$$$$$$$$$$$$$$\n");
			      }
			else{
			m++;
				if(m==1) strcpy(kbuf,tbuf);
				else{
					m=0;
					strcpy(jbuf,tbuf);
				}
		         }
		}

		break;
	case 4:
		fseek(fp1,0,0);
                printf("What do you want:");
                scanf("%s",wbuf);
		while ( fgets (tbuf, sizeof(tbuf), fp1) !=NULL){
               		 p=strstr(tbuf,wbuf);
			 if(p){
			
			
			 	
				printf("%s\n",kbuf);
				
				printf("%s\n",tbuf);
				fgets (tbuf, sizeof(tbuf), fp1);
				printf("%s\n",tbuf);
				printf("$$$$$$$$$$$$$$$$$\n");
			}
			else
			strcpy(kbuf,tbuf);
				
				
			
		}
   		break;
	case 5:return 0;
        default:printf("Input Error!!");return 0;
	}
	}
	fclose(fp1);
	}
	return 0;
}

/**************************************************************
 check movie list version for update
***************************************************************/
int udp_detection (char* ip){
 

//	int cPort = DEFAULT_PORT;
	int cPort = 6000;  
  int cClient = 0;
    unsigned int cLen = 0;
    int cSend = 0;
    int cRecv = 0;
    char send_buf[128] = {0};
    char recv_buf[4096] = {0};
    struct sockaddr_in cli;
 
    memset(recv_buf, 0, sizeof(recv_buf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(ip);
   
    cClient = socket(AF_INET, SOCK_DGRAM, 0);
    if(cClient < 0)
    {
        printf("UDP_socket() failure!\n");
        return -1;
    }
   
    cLen = sizeof(cli);
	
	FILE* pp=fopen("movielist.txt","r");
	if(!pp){
		printf("UDP_file not exist\n");
		return -1;
		}
	fgets(send_buf,sizeof(send_buf),pp);
	fgets(send_buf,sizeof(send_buf),pp);

  while(1){
    cSend = sendto(cClient, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&cli, cLen);
    if((cSend < 0)||(sendto == 0))
    {
        printf("UDP_sendto() failure!\n");
        break;
    }
    else
    {
          printf("UDP_sendto() succeeded.\n");
    }
   
    cRecv = recvfrom(cClient, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&cli, (unsigned int*)&cLen);
    if((cRecv < 0)||(cRecv == 0))
    {
        printf("UDP_recvfrom() failure!\n");
       break;
    }
    else{
	if(strncmp(recv_buf,"movielist.txt is renew",20) ==0) flag=1;
   	 printf("UDP_recvfrom():%s\n",recv_buf);
	break;
	}
	
    }
	fclose(pp);
    close(cClient);
   
    return 0;
	
	
}	
int download(char *ip){
     int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cLen = 0,cLen1=0;
    struct sockaddr_in cli;
    char cbuf[128] = {0};
     int sSend = 0;
//   char sbuf[128] = {0};
     char sbuf[128] ="movielist.txt";  
     memset(cbuf, 0, sizeof(cbuf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(ip);
   

//	printf("which file do you want :");
//	scanf("%s",sbuf);

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
 
	 sSend = send(cClient, sbuf, sizeof(sbuf), 0);
       
        if((sSend < 0)||(sSend == 0))
        {
            printf("send() failure!\n");
            return -1;
        }
        else
        {
            printf("send() byte: [%d]\n", sSend);
        }
	
	
	 FILE *fp=fopen(sbuf,"w");
	if(!fp)
	{fclose(fp);
	printf("Creat file error\n");
	return -1;
	}

    while(1){
    cLen = recv(cClient, cbuf, sizeof(cbuf),0);   
    if((cLen < 0)||(cLen == 0))
    {
          printf("OK!\n");
       	 break;
    }
	if(cLen1==0){
		cLen1++;
	      if(strcmp(cbuf,"This file is not exist!") ==0 ) {
		printf("This file is not exist\n");
		return -1;
		}
	
   	}
	
	if(fputs(cbuf,fp) ==EOF)
		break;

	
   }
 
   
    close(cClient);
	fclose(fp);

	
    return 0;


}	

#if 1
int main(int argc, char** argv)
{
   
     int y=0;
  
    if(argc < 2)
    {
        printf("Uasge: client[server IP address]\n");
        return -1;
    }
	
     char *ipaddr=argv[1];


     printf("1.Test version\n");
     printf("2.Download\n");
     printf("3.Information\n");
     scanf("%d",&y);
     switch(y){
		case 1:
			udp_detection(ipaddr);
			if(flag==1)
			download(ipaddr);
			break;
		case 2: 
			download(ipaddr);
			break;
		case 3:
			search();
			break;
		default:
			printf("Input error\n");
			return 0;
	}



   return 0;



   
}
#endif

