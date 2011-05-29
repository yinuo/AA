/* client_udp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050

int udp_client(char *y)
{
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    unsigned int cLen = 0;
    int cSend = 0;
    int cRecv = 0;
    char send_buf[1024] ={0};
    char recv_buf[1024] = {0};
    struct sockaddr_in cli;
    FILE *file;
    char flag1[]="movielist is not changed!";
    char flag2[]="movielist is changed!";

    file = fopen("1.txt","r");
    /*if(x < 2)
    {
        printf("Uasge:client[server IP address]\n");
        return -1;
    }
   */
    memset(recv_buf, 0, sizeof(recv_buf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(y);

    cClient = socket(AF_INET, SOCK_DGRAM, 0);
    if(cClient < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }

    if(fgets(send_buf,sizeof(send_buf),file)!=NULL)
    if(fgets(send_buf,sizeof(send_buf),file)!=NULL)

    cLen = sizeof(cli);
    cSend = sendto(cClient, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&cli, cLen);
    if((cSend < 0)||(cSend == 0))
    {
        printf("sendto() failure!\n");
        return -1;
    }
   /* else
    {
          printf("sendto() succeeded.\n");
    }
    */
    cRecv = recvfrom(cClient, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&cli, (unsigned int*)&cLen);
    
    if((cRecv < 0)||(cRecv == 0))
    {
        printf("recvfrom() failure!\n");
        return -1;
    }
    
    //if(strncmp(recv_buf,flag1,25)==0)
	//return 0;
	//printf("%s\n",recv_buf);
    if(strncmp(recv_buf,flag2,22)==0)
        return 1;
	//printf("%s\n",recv_buf);
    fclose(file);

    close(cClient);
   
    return 0;
}
