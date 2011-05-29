#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    //printf("%d\n",n);
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
//printf("%d\n",strlen(name[1]));
    while(1){
    printf("1.select by name\n");
    printf("2.select by director\n");
    printf("3.select by year\n");
    printf("4.display all the directors\n");
    printf("5.exit\n");
    printf("Your choice[1-5]:\t");
    scanf("%d",&m);

    switch(m){
        case 1:
    	printf("Input the name:\t");
    	scanf("%s",ch);
    	for(i=0;i<n;i++)	
            if(strncmp(name[i],ch,strlen(name[i])-2)==0){
                printf("\nName @ :%s",name[i]);
	        printf("Director @ :%s",director[i]);
	        printf("Year @ :%s\n",year[i]);
	        break;
	    }
	    if(i==n)
		printf("no such movie!\n\n");
	
	break;

        case 2:
	printf("Input the director:\t");
    	scanf("%s",ch);
        printf("\n***movies directed by %s***\n\n",ch);
    	for(i=0;i<n;i++)
            if(strncmp(director[i],ch,strlen(director[i])-2)==0){
	        printf("Name @ :%s",name[i]);
	    	printf("Year @ :%s\n",year[i]);
	    }
	    
	break;

        case 3:
	printf("Input the year:\t");
    	scanf("%s",ch);
	printf("\n***movies directed in %s***\n\n",ch);
    	for(i=0;i<n;i++)
            if(strncmp(year[i],ch,strlen(year[i])-2)==0){
	        printf("Name @ :%s",name[i]);
	    	printf("Director @ :%s\n",director[i]);
	    }

	break;

        case 4:
	printf("\n***all the directors***\n\n");
	printf("%s",director[0]);
	for(i=1;i<n;i++)
	    for(j=i-1;j>=0;j--){
		if(strcmp(director[j],director[i])==0)
		    break;
	 	if(j==0)
	    	    printf("%s",director[i]);	    
	    }
	printf("\n");
	      
	break;

        case 5:return -1;

        default:break;
    }
    }
    fclose(file);
    return 0;
}

