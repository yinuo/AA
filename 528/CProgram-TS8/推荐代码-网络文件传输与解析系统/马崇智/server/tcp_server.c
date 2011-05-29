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

int tcp_server()
{
    int sPort = DEFAULT_PORT;
    int sListen = 0;
    int sAccept = 0;
    unsigned int sLen = 0;
    int sSend = 0;
    struct sockaddr_in ser;
    struct sockaddr_in cli;  
    char sbuf[1024]={0};
    FILE * file; 
     
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
   
    if(listen(sListen, 5) < 0)  //定义连接数
    {
        printf("listen() failure!\n");        
        return -1;
    }
 
    sLen = sizeof(cli);
    while(1){
    file = fopen("../MovieList/v1.00/movielist.txt","r");
    while(1)
    {    
 	
        sAccept = accept(sListen, (struct sockaddr*)&cli, (unsigned int*)&sLen);
        if(sAccept < 0)
        {
            printf("accept() failure!\n");           
            break;
        }
         
        printf("accept() client IP: [%s]\n", (char*)inet_ntoa(cli.sin_addr));  //记录IP
        printf("accept() client PORT: [%d]\n", ntohs(cli.sin_port));
        
	if(fgets(sbuf,sizeof(sbuf),file)==NULL)
	    break;
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
        close(sAccept);
    }
   
    fclose(file);
    strcpy(sbuf,"the end of the file!");
    sSend = send(sAccept, sbuf, sizeof(sbuf), 0);
    }
    close(sListen);  

    return 0;
}
