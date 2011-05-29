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
#define DEFAULT_PORT1 5051


int download( char *IP);
int simple_search(const char *str,FILE *fp);
int complex_search(int n ,FILE *fp);
int analysis(void);

/*  download  */
int download( char *IP)
{
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cLen ;
    FILE *q = NULL;
    struct sockaddr_in cli;
    char cbuf[1024] = {0};

     q = fopen("list.txt","w");   
     if(q == NULL)
     { printf( "The file 'list.txt' was not opened\n" );}
   
    memset(cbuf, 0, sizeof(cbuf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(IP);
   
    cClient = socket(AF_INET, SOCK_STREAM, 0);//tcp/ip
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
    while(1)
    { cLen = recv(cClient, cbuf, sizeof(cbuf),0);  
      

      if(cLen<0 )
       {
          printf("recv() failure!\n");
         
          break;
       
       }
     if(0 == cLen)
      {break;}

      if(fputs(cbuf,q) ==EOF)
	break;
         printf("recv() Data From Server: %s\n", cbuf);
     
    
 }
  

    close(cClient);
   fclose(q);
   
    return 0;
}



/*   simple_search  */
int simple_search(const char *str,FILE *fp)
{
  char buffer[1024] = {};
  char *p1;
  while(!feof(fp))
 {
  if(fgets(buffer,1024,fp) == NULL)
   return 0;
    p1 = strstr(buffer,str);
    if(p1 != NULL)
    
    printf("%s\n",p1);
}
  return 0;
}


/*  complex_search  */
int complex_search(int n ,FILE *fp)
{    
    int flag1 = 0;
   
    int flag = 0;
    int count = 0;
    char buffer[1024] = {};
    char str[100] = {};
    struct {
        char name[1024];
        char director[1024];
        char year[1024];
    }movie;

   scanf("%s",str);

     while(!feof(fp))
    {
        if(fgets(buffer,1024,fp) ==NULL)
            break;
        if(strstr(buffer,"Name") != NULL)
            strncpy(movie.name,buffer,strlen(buffer)+1);
        else if(strstr(buffer,"Director") != NULL)
            strncpy(movie.director,buffer,strlen(buffer)+1);
        else if(strstr(buffer,"Year") != NULL)
        {
            strncpy(movie.year,buffer,strlen(buffer)+1);
            flag1 = 1;
        }
        else 
            continue;

        if(!flag1) 
            continue;
          switch(n)             
       {
            case 4:if(strstr(movie.name,str) != NULL)
                        flag = 1;
                        break;
            case 5:if(strstr(movie.director,str) != NULL)
                        flag = 1;
                        break;
            case 6:if(strstr(movie.year,str) != NULL)
                        flag = 1;
                        break;
        }
        if(flag)
        {
            printf("%s\n",movie.name);
            printf("%s\n",movie.director);
            printf("%s\n",movie.year);

            flag = 0;
            count ++;
        }

        flag1 = 0;         
    }

    if(0==count)
        printf("can't find the movie\n");
    else 
        printf("the quantity of movie is %d \n",count);
    return 0;
}




/*  analysis   */
int analysis(void)
{
 int m;
 FILE *fq;
 
start: fq = fopen("list.txt","r");   
     if(fq == NULL)
   {
    printf( "The file 'movielist.txt' was not opened or not exist,please download\n" );
    return 0; 
   }
       printf("1.list all the name\n");
       printf("2.list all the director\n");
       printf("3.list all the year\n");
       printf("4.search the movie bye  name in all\n");
       printf("5.search the movie by director in all\n");
       printf("6.search the movie by year in all\n");
       printf("7.go back to previous level\n");
       
       printf("your choose[1-7]:\n");
       scanf("%d",&m);
  
 switch(m)
 {
  case 1:simple_search("Name",fq);
         fclose(fq);
         goto start;
         break;
  case 2:simple_search("Director",fq);
         fclose(fq);
         goto start;
         break;
  case 3:simple_search("Year",fq);
         fclose(fq);
         goto start;
         break;
  case 4:printf("Input the movie name:\n");
         complex_search(m,fq);
         fclose(fq);
         goto start;
         break;
  case 5:printf("Input the movie director:\n");
         complex_search(m,fq);
         fclose(fq);
         goto start;
         break;
  case 6:printf("Input the movie year:\n");
         complex_search(m,fq);
         fclose(fq);
         goto start;
         break;
  case 7:fclose(fq);
        return 0;break;

  default:fclose(fq);
          printf("data error!Please input your choose again\n");
          goto start;
          
} 
  
}


 
int check_update(char *IP)
{   FILE *fp = NULL;
    int cPort = DEFAULT_PORT1;
    int cClient = 0;
    unsigned int cLen = 0;
    int cSend = 0;
    int cRecv = 0;
   
    char send_buf[1024] = {};
    char recv_buf[4096] = {0};
    char buffer[1024] = {};
    char buffer1[1024] = "need update";
    struct sockaddr_in cli;
   
   
   
    memset(recv_buf, 0, sizeof(recv_buf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(IP);
   
    cClient = socket(AF_INET, SOCK_DGRAM, 0);
    if(cClient < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
    fp = fopen("list.txt","r");
    if(fp == NULL)
    { printf("don't open the file\n");
      return 0;
    }
    while(!feof(fp))
    {
     if(fgets(buffer,1024,fp) != NULL)
      { 
        if( strstr(buffer,"Version") != NULL)
            {
              strncpy(send_buf,buffer,strlen(buffer)+1);
               break;
             }
      }
   }
    cLen = sizeof(cli);
    cSend = sendto(cClient, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&cli, cLen);
    if((cSend < 0))
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
  
    fclose(fp);
    close(cClient);
   if(strcmp(recv_buf,buffer1) == 0)
      {return 1;
       
      }
   else
      return 0;
}

/* main */
int main(int argc, char** argv)
{ 
   int t = 0;
  
          if(argc < 2)
    {
        printf("Uasge: client[server IP address]\n");
        return -1;
    }

   
 start1:
       printf("1.download file\n");
       printf("2.inspect and update file's edition\n");
       printf("3.analysisi file\n");
       printf("4.exit\n");
       printf("Please input your choose[1-4]\n");
      scanf("%d",&t);
   switch(t)
  {
   case 1:download(argv[1]);
          goto start1;
          break;

   case 2:if(check_update(argv[1]) == 1)
           
          {download(argv[1]);}
           
             goto start1;
             break;
             
   case 3:if(analysis() == -1);
           
           goto start1;
            break;
   case 4:return 0;
   default:
         printf("data error!Please input your choose again\n");
          goto start1;
          break;
  }
         
 return 0;
}








