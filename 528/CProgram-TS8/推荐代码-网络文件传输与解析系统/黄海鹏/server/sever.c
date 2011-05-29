/* server_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050
#define DEFAULT_PORT1 5051
int child_process()
{
    int sPort = DEFAULT_PORT;
    int sListen = 0;
    int sAccept = 0;
    unsigned int sLen = 0;
    int sSend = 0;
    FILE *p = NULL;
   char sbuf[1024] ;
   //char buffer[1024] = {};
    struct sockaddr_in ser;
    struct sockaddr_in cli;
 
  
   printf("Child process id is %d\n", getpid());
   while(1)
 {
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
          p = fopen("movielist.txt","r");
    if(p == NULL)
     { printf( "The file 'movielist.txt' was not opened\n" );}
          while(fgets(sbuf,sizeof(sbuf),p) != NULL)
         {
         
          printf("%s\n",sbuf);
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
       fclose(p);
   close(sAccept); 
}
   
    close(sListen);
 }  
   sleep(1);
}


int main(int argc, char* argv[])
{
      FILE *fp = NULL;
    int sPort = DEFAULT_PORT1;
    int sSocket = 0;
    int sLen = 0;
    int sSend = 0;
    int sRecv = 0;
    int flag = 0;
    char send_buf1[1024] = "need update";
    char send_buf2[1024] = "don't need update";
    char buffer[1024] = {};
      char recv_buf[4096] = {0};
    struct sockaddr_in ser;
    struct sockaddr_in cli;
    pid_t pid;//pid_t == unsigned int     Process ID _ Type

    pid = fork();
    
    if (pid == 0)
    {
        child_process();
    }
    else
    {
    	  printf("Parent process id is %d\n", getpid());
    	  
        while(1)
        { 
   
            printf("Server waiting...\n");
   
             sSocket = socket(AF_INET, SOCK_DGRAM, 0);
             if(sSocket < 0)
           {
             printf("socket() failure!\n");
             return -1;
             }
   
            ser.sin_family = AF_INET;
            ser.sin_port = htons(sPort);
            ser.sin_addr.s_addr = htonl(INADDR_ANY);
   
             if(bind(sSocket, (struct sockaddr*)&ser, sizeof(ser)) < 0)
           {
            printf("bind() failure!\n");
            return -1;
            }
   
           sLen = sizeof(cli);
           memset(recv_buf, 0, sizeof(recv_buf));
   
          while(1)
          {
           sRecv = recvfrom(sSocket, recv_buf, 4096, 0, (struct sockaddr*)&cli, (unsigned int*)&sLen);
           if((sRecv < 0)||(sRecv == 0))
           {
              printf("recvfrom() failure!\n");
            break;
           }
          else
           {
              fp = fopen("movielist.txt","r");
              if(fp == NULL)
            { printf("don't open the file\n");
             return 0;
             }
           while(!feof(fp))
            {
           if(fgets(buffer,1024,fp) != NULL)
             { 
              if( strstr(buffer,"Version") != NULL)
              {
              
                  if(strcmp(recv_buf,buffer) !=0)
                   flag = 1;
                  break;
              }
          }
        }
            printf("recvfrom(): [%s]\n", recv_buf);            
            printf("recvfrom() client IP: [%s]\n", inet_ntoa(cli.sin_addr));
            printf("recvfrom() client PORT: [%d]\n", ntohs(cli.sin_port));
        }
      if(flag)
        {sSend = sendto(sSocket, send_buf1, sizeof(send_buf1), 0, (struct sockaddr*)&cli, sizeof(cli));flag = 0;}
     
      else
      
        {sSend = sendto(sSocket, send_buf2, sizeof(send_buf2), 0, (struct sockaddr*)&cli, sizeof(cli));}
        if((sSend < 0)||(sSend == 0))
        {
              printf("sendto() failure!\n");
            break;
        }
        printf("sendto() Succeeded!\n");
    }
    fclose(fp);
    close(sSocket);
    
   
   

    		    sleep(1);//用于延迟挂起进程
        }
    
    }
    return 0;
}
