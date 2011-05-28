#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define DEFAULT_PORT 5050

int udp_client(char *x){
	
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    unsigned int cLen = 0;
    int cSend = 0;
    int cRecv = 0;
    char l[] = "Version";
    char j[1024] = {0}; 
    char *send_buf;    
    FILE *file;

    file = fopen("1.txt","r+");
    if(!file){
	printf("faile to open");
    }
    while(1){
    if(fgets(j,sizeof(j),file) == NULL)
	return 0;
    else
    send_buf = strstr(j,l);
    if(send_buf)
	break;	
    }

    char recv_buf[4096] = {0};
    struct sockaddr_in cli;
   /*
    if(argc < 2)
    {
        printf("Uasge:client[server IP address]\n");
        return -1;
    }*/
   
    memset(recv_buf, 0, sizeof(recv_buf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(x);
   
    cClient = socket(AF_INET, SOCK_DGRAM, 0);
    if(cClient < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    cLen = sizeof(cli);
    cSend = sendto(cClient, send_buf, strlen(send_buf), 0, (struct sockaddr*)&cli, cLen);
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
     if(strcmp(recv_buf,send_buf))
	printf("存在新版本，请更新\n");
     else
	printf("不存在新版本\n");	
    close(cClient);
return 0;
}


int tcp_client(char *y){

    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cLen = 0;
    struct sockaddr_in cli;
    char cbuf[4096] = {0};
    FILE *dest;
    dest = fopen("1.txt","w+");
   
   /* if(argc < 2)
    {
        printf("Uasge: client[server IP address]\n");
        return -1;
    }*/
   
    memset(cbuf, 0, sizeof(cbuf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(y);
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
    if((cLen < 0)||(cLen == 0))
    {
        return -1;
    }
   
    fputs(cbuf,dest);

    printf("recv() Data From Server: [%s]\n", cbuf);
    }
    fclose(dest);
    close(cClient);
   

return 0;
}



int jiexi(int z){

    FILE * file;
    int n=0,i=0,j=0;
    char name[10][50]={0};
    char director[10][50]={0};
    char year[10][50]={0};
    char cbuf[100]={0};
    char ch[50];
   
    file = fopen("1.txt","r");
    while(1){	
	if(fgets(cbuf,sizeof(cbuf),file)==NULL)
		break;
	if(strncmp(cbuf,"Name",4)==0)
		n++;		
    }	
    fclose(file);

    file = fopen("1.txt","r");
    while(1){	
	if(fgets(cbuf,sizeof(cbuf),file)==NULL)
		break;
	if(strncmp(cbuf,"Name",4)==0){
	    for(j=0;cbuf[j+8]!='\0';j++)
	        name[i][j]=cbuf[j+8];
 	}
		
	if(strncmp(cbuf,"Director",8)==0){
	    for(j=0;cbuf[j+12]!='\0';j++)
	        director[i][j]=cbuf[j+12];
	}
		
	if(strncmp(cbuf,"Year",4)==0){
	    for(j=0;cbuf[j+8]!='\0';j++)
	        year[i][j]=cbuf[j+8];	
	    i++;	    
        }
				
    }
     fclose(file);

     while(1){
	
	switch(z){
		case 1:
			for(i = 0;i < n;i++)
			printf("\nName @ :%s",name[i]);
			return 0;
			break;
		case 2:
			for(i = 0;i < n;i++)
			printf("\nDirector @ :%s",director[i]);
			return 0;
			break;
		case 3:
			printf("please input the year\n");
	    		scanf("%s",ch);
    			for(i=0;i<n;i++)
            			if(strncmp(year[i],ch,4) == 0){	        		
				printf("Name @ :%s",name[i]);
	    			printf("Director @ :%s\n",director[i]);
				}
			return 0;
			break;
		case 4:
			printf("please input the director\n");
			scanf("%s",ch);
		    	for(i=0;i<n;i++)
            			if(strncmp(director[i],ch,strlen(director[i])-2)==0){
	        		printf("Name @ :%s",name[i]);
	    			printf("Year @ :%s\n",year[i]);
				}
			return 0; 
			break;
		default:
			exit(0);
			break;	
		}

    }
    fclose(file);
}
int main(int argc,char **argv){
	printf("1.检测版本是否有更新\n");
	printf("2.更新版本\n");
	printf("3.解析文件\n");	
	printf("4.make your choice");
 	int a,b;
	char *w;
	w = malloc(30);
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("Uasge:client[server IP address]\n");
			scanf("%s",w);
			udp_client(w);
			break;
		case 2:
			printf("Uasge:client[server IP address]\n");
			scanf("%s",w);
			tcp_client(w);
			break;
		case 3:
			printf("1.name\n");
    			printf("2.director\n");
			printf("3.by year\n");
			printf("4.by dirname\n");
			printf("Your choice \t");
			scanf("%d",&b);
			jiexi(b);
			break;
		default:
			exit(0);
			break;

        }



	return 0;
}
