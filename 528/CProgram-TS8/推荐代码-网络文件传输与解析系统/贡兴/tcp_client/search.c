#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
#if 0
FILE *fp1=NULL; 
fp1=fopen("movielist.txt","r");
typedef struct movie_info 
{ 
 char name[128]; 
 
 char director[128];
 char year[128];
 struct movie_info *next;  
}Movie; 
Movie *head_1; /*为全局变量*/


Movie *load() /*载入函数,从文件中读数据建立链表*/ 
{  
  
 Movie *p=NULL,*q=NULL; 
 char mbuf[128]={0};
 
 if(fp1==NULL)
 {
   printf("Can't open\n");
  return head_1;
 } 
 p=(Movie*)malloc(sizeof(Movie)); 
 if(fgets(mbuf,sizeof(mbuf),fp1)==NULL)
  return head_1; 
 head_1=p; 
 while(fgets(mbuf,sizeof(mbuf),fp1)!=NULL) 
 {
  q=p; 
  p=(Movie*)malloc(sizeof(Movie)); 
  fgets(mbuf,sizeof(mbuf),fp1);
  	while((strstr(mbuf,"Name")) ==NULL){
		fgets(mbuf,sizeof(mbuf),fp1);
		}  
	p->name=mbuf;
	fgets(mbuf,sizeof(mbuf),fp1);
	p->director=mbuf;
	fgets(mbuf,sizeof(mbuf),fp1);
	p->year=mbuf;
  	
  q->next=p; 
 } 
 q->next=NULL; 
 free(p); 
 fclose(fp1); 
 return head_1; 
} 
#endif

	
	char tbuf[256]={0};
	int n=0;
	char *p=NULL;
	char wbuf[128]={0};
	char kbuf[128]={0};
	char jbuf[128]={0};
	float m=0;
	FILE *fp1=fopen("movielist.txt","r");
	if(!fp1){
		printf("Can't open\n");
		return -1;
	}
	else{
	
	while(1){
	printf("*****************************\n");
	printf("****1.name     list    ******\n");
	printf("****2.derictor list    ******\n");
        printf("****3.list by year     ******\n");
	printf("****4.others           ******\n");
	printf("****5.       Exit      ******\n");
        printf("Please choose:\n");
	scanf("%d",&n);
	switch(n){
	case 1:
		fseek(fp1,0,0);
		 while ( fgets (tbuf, sizeof(tbuf), fp1) != NULL)
    			{      			 
			   p=strstr(tbuf,"Name");
			    if(p){
   				printf("%s \n",p);
			     }
			}
  		break;
	
	case 2:fseek(fp1,0,0);
		while ( fgets (tbuf, sizeof(tbuf), fp1) != NULL)
    			{
      			
			   p=strstr(tbuf,"Director");
			    if(p){
   				printf("%s \n",p);
			     }
			}
  		break;
	case 3: 
		fseek(fp1,0,0);
        	printf("Witch year:");
        	scanf("%s",wbuf);
       		while ( fgets (tbuf, sizeof(tbuf), fp1) !=NULL){
               		 p=strstr(tbuf,wbuf);
			 if(p){						 	
				printf("%s\n",kbuf);
				printf("%s\n",jbuf);
				printf("%s\n",tbuf);
				printf("$$$$$$$$$$$$$$$$$\n");
			      }
			else{
			m++;
				if(m==1) strcpy(kbuf,tbuf);
				else{
					m=0;
					strcpy(jbuf,tbuf);
				}
		         }
		}

		break;
	case 4:
		fseek(fp1,0,0);
                printf("What do you want:");
                scanf("%s",wbuf);
		while ( fgets (tbuf, sizeof(tbuf), fp1) !=NULL){
               		 p=strstr(tbuf,wbuf);
			 if(p){
			
			
			 	
				printf("%s\n",kbuf);
				
				printf("%s\n",tbuf);
				fgets (tbuf, sizeof(tbuf), fp1);
				printf("%s\n",tbuf);
				printf("$$$$$$$$$$$$$$$$$\n");
			}
			else
			strcpy(kbuf,tbuf);
				
				
			
		}
   		break;
	case 5:return 0;
        default:printf("Input Error!!");return 0;
	}
	}
	fclose(fp1);
	}
	return 0;
}
