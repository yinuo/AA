#include <stdio.h>
#include <stdlib.h>
#include "tcp_client.h"
#include "jiexi.h"
#include "udp_client.h"

int main(int argc,char *argv[]){
    int m; 
    char str[30]={0};
    int t=0;
    
    while(1){
    printf("1.检查更新\n");
    printf("2.下载\n");
    printf("3.解析\n");
    printf("4.退出\n");
    printf("Your choice[1-4]:\t");
    scanf("%d",&m);

    switch(m){
        case 1:
	    printf("\n请输入server IP: ");
	    scanf("%s",str);
	    t = udp_client(str);
            if(t==1){
                printf("\n检测到新版本，并自动更新!");				
		tcp_client(str);
	    }
            else
                printf("\n没有更新!\n");

            break;

        case 2:
	    printf("\n请输入server IP: ");
	    scanf("%s",str);
            tcp_client(str);

            break;

        case 3:
	    printf("\n");
            jiexi();
            break;
        
        case 4:exit(0);

        default:
            break;
    }
	printf("\n");
    }
	return 0;
}
