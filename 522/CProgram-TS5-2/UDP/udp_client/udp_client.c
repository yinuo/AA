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

int main(int argc, char*argv[])
{
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    unsigned int cLen = 0;
    int cSend = 0;
    int cRecv = 0;
    char send_buf[] = "Hello! I Am a Client!";
    char recv_buf[4096] = {0};
    struct sockaddr_in cli;
   
    if(argc < 2)
    {
        printf("Uasge:client[server IP address]\n");
        return -1;
    }
   
    memset(recv_buf, 0, sizeof(recv_buf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(argv[1]);
   
    cClient = socket(AF_INET, SOCK_DGRAM, 0);
    if(cClient < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    cLen = sizeof(cli);
    cSend = sendto(cClient, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&cli, cLen);
    if((cSend < 0)||(sendto == 0))
    {
        printf("sendto() failure!\n");
        return -1;
    }
    else
    {
          printf("sendto() succeeded.\n");
    }
   
    cRecv = recvfrom(cClient, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&cli, (unsigned int*)&cLen);
    if((cRecv < 0)||(cRecv == 0))
    {
        printf("recvfrom() failure!\n");
        return -1;
    }
   
    printf("recvfrom():%s\n",recv_buf);
    close(cClient);
   
    return 0;
}
