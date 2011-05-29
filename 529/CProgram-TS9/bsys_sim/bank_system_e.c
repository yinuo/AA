/* Bank System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue_queue.c"

#define USE_LINE_QUEUE
/////////////////////////////////////////////////////////////////
SqQueue sq,sq1;

//SqQuene sq1;

#define BSYS_MAX_USER_NUM     1000

/***************************************************************
* Bank System Initid
****************************************************************/
int Bank_Sys_Init(void)
{
	QueueCreate(&sq);
	QueueCreate(&sq1);
	return 0;
}

/***************************************************************
* Bank System Quit
****************************************************************/
int Bank_Sys_Term(void)
{
	QueueDestroy(&sq);
	QueueDestroy(&sq1);
	return 0;    
}

/***************************************************************
* Bank Get One ID
****************************************************************/
int Bank_Sys_Get_Id(int Id)
{
	#ifdef USE_LINE_QUEUE
	QueueEnterL(&sq,Id);
	#else //USE_CIRCLE_QUEUE
	QueueEnterC(&sq,Id);
	#endif	
	return 0;
}


int Bank_Sys_Get_Id1(int Id)
{
	#ifdef USE_LINE_QUEUE
	QueueEnterL(&sq1,Id);
	#else //USE_CIRCLE_QUEUE
	QueueEnterC(&sq1,Id);
	#endif	
	return 0;
}//vip
/***************************************************************
* Bank Call One ID
****************************************************************/
unsigned int Bank_Sys_Call_Id(void)
{
	int uid;
	#ifdef USE_LINE_QUEUE
	QueueDeleteL(&sq, &uid);
	#else //USE_CIRCLE_QUEUE
	QueueDeleteC(&sq, &uid);	
	#endif	
	printf("%d",uid);
	return uid;
}



unsigned int Bank_Sys_Call_Id1(void)
{
	int uid;
	#ifdef USE_LINE_QUEUE
	QueueDeleteL(&sq1, &uid);
	#else //USE_CIRCLE_QUEUE
	QueueDeleteC(&sq1, &uid);	
	#endif	
	printf("%d",uid);
	return uid;
}//vip
/***************************************************************
* Bank Get All Users Number
****************************************************************/
unsigned int Bank_Get_User_Num(void)
{
	int num;	
	num = QueueGetTag(&sq);
	
	return num;
}



unsigned int Bank_Get_User_Num1(void)
{
	int num;	
	num = QueueGetTag(&sq1);
	
	return num;
}//vip
/***************************************************************
* Bank Get All Users Number
****************************************************************/
int main(int argc, char**argv)
{
 	char virtkey = 0;
	int a = 0,b = 0;
	int tags = 0;
        int c;
	Bank_Sys_Init();
	      	
	for(;;)
	{
        scanf("%c", &virtkey); 
        
        switch(virtkey)
        {
        	   case 'g':
			printf("请输入你的身份:");
			scanf("%d",&c);
			switch(c){
				case 1:
					Bank_Sys_Get_Id1(a);
					a++;
					tags = 1;
					if(Bank_Get_User_Num1() == 0)
					a = a;
					break;
				case 2:
					Bank_Sys_Get_Id(b);
					b++;
					if(Bank_Get_User_Num() == 0)
					b = b;					
					break;	
				default:
					//printf("输入错误，请重新输入\n");
					break;
			}
        	     break;
        	     
        	   case 'c'://叫号
			if(1 == tags){
				printf("\nvip\t");
				Bank_Sys_Call_Id1();
				if(Bank_Get_User_Num1() == 0)
					{tags = 0;}			
			}
			else{
			printf("\n普通客户\t");
			Bank_Sys_Call_Id();
			}
        	     break;
        	     
        	   case 'u'://显示所有用户的数量
			printf("普通客户的当前数量为%d:\n",Bank_Get_User_Num());
			printf("vip客户的当前数量为%d:\n",Bank_Get_User_Num1());			

        	     break;
        	     
        	   case 'e':
	                goto BSYSEXIT;
        	     break;        	     
        	   
        	   default:     	   	   
        	   	   if(virtkey != 10) // "ENTER" Key Code (10)
        	   	   {
        	           printf("Error Enter Key!! \n");
        	       }
        	     break;
        }
	}
	  
BSYSEXIT:
	  Bank_Sys_Term();
	  
    return 0;
}
