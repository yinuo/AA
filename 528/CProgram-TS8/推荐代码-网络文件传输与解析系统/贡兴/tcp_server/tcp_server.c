/* server_tcp.c */
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
pthread_mutex_t mutex;


void *udp_detection (void* arg){

   
//    int sPort = DEFAULT_PORT;
	int sPort = 6000;	
    int sSocket = 0;
    int sLen = 0;
    int sSend = 0;
    int sRecv = 0;
    char send_buf[128]={0};
    char ver_buf[128]={0};
      char recv_buf[4096] = {0};
   char y_buf[]="movielist.txt is renew shoud be download again!";
   char n_buf[]="movielist.txt is the newest";
    struct sockaddr_in ser;
    struct sockaddr_in cli;
   
    printf("UDP_Server waiting...\n");
   
    sSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(sSocket < 0)
    {
          printf("UDP_socket() failure!\n");
        return NULL;
    }
   
    ser.sin_family = AF_INET;
    ser.sin_port = htons(sPort);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
   
    if(bind(sSocket, (struct sockaddr*)&ser, sizeof(ser)) < 0)
    {
          printf("UDP_bind() failure!\n");
        return NULL;
    }
   
	 pthread_mutex_lock(&mutex);

        FILE* pp=fopen("movielist.txt","r");
	if(!pp){
		printf("UDP_file not exist\n");
		return NULL;
		}
	fgets(ver_buf,sizeof(send_buf),pp);
	fgets(ver_buf,sizeof(send_buf),pp);
	
        pthread_mutex_unlock(&mutex);
    sLen = sizeof(cli);
    memset(recv_buf, 0, sizeof(recv_buf));
   
    while(1)
   {
        sRecv = recvfrom(sSocket, recv_buf, 4096, 0, (struct sockaddr*)&cli, (unsigned int*)&sLen);
        if((sRecv < 0)||(sRecv == 0))
        {
              printf("UDP_recvfrom() failure!\n");
          break;
        }
        else
        {
		if((strcmp(ver_buf,recv_buf))>0)
		   strcpy(send_buf,y_buf);
		else
		   strcpy(send_buf,n_buf);
        //    printf("recvfrom(): [%s]\n", recv_buf);
      //      printf("recvfrom() client IP: [%s]\n", inet_ntoa(cli.sin_addr));
      //      printf("recvfrom() client PORT: [%d]\n", ntohs(cli.sin_port));
        }
       
        sSend = sendto(sSocket, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&cli, sizeof(cli));
        if((sSend < 0)||(sSend == 0))
        {
              printf("UDP_sendto() failure!\n");
            break;
        }
        printf("UDP_sendto() Succeeded!\n");
   }
    close(sSocket);
   
    return 0;
}


int main(int argc, char** argv)
{
    int sPort = DEFAULT_PORT;
    int sListen = 0;
    int sAccept = 0;
    unsigned int sLen = 0;
    unsigned int cLen = 0;
    int sSend = 0,sSend1=0;
    struct sockaddr_in ser;
    struct sockaddr_in cli;
    char sbuf[128] = {0};
    char cbuf[4096] = {0};
   char gbuf[128]="This file is not exist!";
    pthread_mutex_init(&mutex,NULL);
  pthread_t thread;
 
  pthread_create (&thread, NULL, &udp_detection, NULL);


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
        sAccept = accept(sListen, (struct sockaddr*)&cli, (unsigned int*)&sLen);
        if(sAccept < 0)
        {
            printf("accept() failure!\n");             
            break;
        }
       
        printf("accept() client IP: [%s]\n", (char*)inet_ntoa(cli.sin_addr));
        printf("accept() client PORT: [%d]\n", ntohs(cli.sin_port));


//
	cLen = recv(sAccept, cbuf, sizeof(cbuf),0);   
    if((cLen < 0)||(cLen == 0))
    {
          printf("recv() failure!\n");
        return -1;
    }
    printf("recv() Data From Client: [%s]\n", cbuf);
	FILE *fp=fopen(cbuf,"r");
	if(!fp){
		
	//	fclose(fp);
		sSend1=send(sAccept, gbuf,sizeof(gbuf),0);
		 if((sSend1 < 0)||(sSend1 == 0))
       		 {
         	   printf("send() failure!\n");
         	   break;
       		 }
        	else
       		 {
            	   printf("send() byte: [%d]\n", sSend1);
        	 }
		return -1;
	}
	else{
	while (fgets (sbuf, sizeof(sbuf), fp) != NULL)
    	{
             
        sSend = send(sAccept, sbuf, sizeof(sbuf), 0);
       
       		 if((sSend < 0)||(sSend == 0))
       		 {
         	   printf("send() failure!\n");
         	   break;
       		 }
        	else
       		 {
            	   printf("send() byte: [%d]\n", sSend);
        	 }
	}
	fclose(fp);
	}
	
   



        close(sAccept);
    }
    close(sListen);
   
    return 0;
}
