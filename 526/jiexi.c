#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int jiexi(){
    FILE * file;
    int n=0,i=0,j=0;
    char name[10][50]={0};
    char director[10][50]={0};
    char year[10][50]={0};
    char cbuf[100]={0};
    int m; 
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
    	printf("1.name\n");
    	printf("2.director\n");
	printf("3.by year\n");
	printf("4.by dirname\n");
	printf("Your choice \t");

	scanf("%d",&m);
	switch(m){
		case 1:
			for(i = 0;i < n;i++)
			printf("\nName @ :%s",name[i]);
			break;
		case 2:
			for(i = 0;i < n;i++)
			printf("\nDirector @ :%s",director[i]);
			break;
		case 3:
			printf("please input the year\n");
	    		scanf("%s",ch);
    			for(i=0;i<n;i++)
            			if(strncmp(year[i],ch,4) == 0){	        		
				printf("Name @ :%s",name[i]);
	    			printf("Director @ :%s\n",director[i]);
				}
			break;
		case 4:
			printf("please input the director\n");
			scanf("%s",ch);
		    	for(i=0;i<n;i++)
            			if(strncmp(director[i],ch,strlen(director[i])-2)==0){
	        		printf("Name @ :%s",name[i]);
	    			printf("Year @ :%s\n",year[i]);
				}
			break;  
		default:
			exit(0);
			break;  	
		}

    }
    fclose(file);
    return 0;
}




int main(int argc,char **argv){

	int a;

  	printf("1.update\n");
	printf("2.jiexi\n");

	scanf("%d",&a);
	switch(a){
		case 1:
			break;
		case 2: 
			jiexi();
			break;
		default:
			break;

	}
         
	return 0;

}


