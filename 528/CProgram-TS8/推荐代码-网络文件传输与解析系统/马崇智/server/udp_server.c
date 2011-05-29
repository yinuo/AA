/* server_udp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050

int udp_server()
{
    int sPort = DEFAULT_PORT;
    int sSocket = 0;
    int sLen = 0;
    int sSend = 0;
    int sRecv = 0;
    char send_buf[1024]={0};
    char recv_buf[1024] = {0};
    struct sockaddr_in ser;
    struct sockaddr_in cli;
    FILE *file;
    char flag1[]="movielist is not changed!";
    char flag2[]="movielist is changed!";

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
	file = fopen("../MovieList/v1.00/movielist.txt","r");
        if(fgets(send_buf,sizeof(send_buf),file)!=NULL)
	if(fgets(send_buf,sizeof(send_buf),file)!=NULL)

        sRecv = recvfrom(sSocket, recv_buf, 1024, 0, (struct sockaddr*)&cli, (unsigned int*)&sLen);
        if((sRecv < 0)||(sRecv == 0))
        {
              printf("recvfrom() failure!\n");
            break;
        }
        else
        {
            printf("recvfrom(): [%s]\n", recv_buf);
            printf("recvfrom() client IP: [%s]\n", inet_ntoa(cli.sin_addr));
            printf("recvfrom() client PORT: [%d]\n", ntohs(cli.sin_port));
        }
        
	  
	if(strncmp(send_buf,recv_buf,13)==0)
	    strcpy(send_buf,flag1);
	else
	    strcpy(send_buf,flag2);  
	
        sSend = sendto(sSocket, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&cli, sizeof(cli));
        if((sSend < 0)||(sSend == 0))
        {
              printf("sendto() failure!\n");
            break;
        }
        printf("sendto() Succeeded!\n");     
	
	fclose(file);
    }
    

    close(sSocket);

    return 0;
}
