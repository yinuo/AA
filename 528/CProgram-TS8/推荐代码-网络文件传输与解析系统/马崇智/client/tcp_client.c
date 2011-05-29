/* client_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050


int tcp_client(char *y)
{
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cLen = 0;
    struct sockaddr_in cli;
    char cbuf[4096] = {0};
    FILE * file;

  /*  if(x < 2)
    {
        printf("Uasge: client[server IP address]\n");
        return -1;
    }
 */  
    memset(cbuf, 0, sizeof(cbuf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(y);
     
    file = fopen("1.txt","w");
    while(1){   
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
        
    cLen = recv(cClient, cbuf, sizeof(cbuf),0);  
    
    if((cLen < 0) || (cLen == 0)){
	break;
    }
    if(strncmp(cbuf,"the end of the file!",20)==0)
	break;
    fputs(cbuf,file);  
    
    }
        
    fclose(file);    
    //printf("recv() Data From Server: [%s]\n", cbuf);
    close(cClient);
    printf("\n下载成功！\n");
    return 0;
}
