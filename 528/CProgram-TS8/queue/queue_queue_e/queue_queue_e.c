/* queue */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue_queue.c"

//#define USE_LINE_QUEUE

void queue_app_test(void)
{
	  unsigned int iloop = 0;
	  int data = 0;
    SqQueue sq;
    
    QueueCreate(&sq);
    
    for(iloop=0; iloop < 16; iloop++)
    {
    	#ifdef USE_LINE_QUEUE
        QueueEnterL(&sq, iloop*8);
      #else //USE_CIRCLE_QUEUE
        QueueEnterC(&sq, iloop*8);     
      #endif
        printf("queue get valid data len is %d \n", QueueGetTag(&sq));            
    }
    
  #ifdef USE_LINE_QUEUE
    while(QueueDeleteL(&sq, &data) != -1)
  #else //USE_CIRCLE_QUEUE
    while(QueueDeleteC(&sq, &data) != -1)
  #endif      
    {
        printf("queue get data value is %d \n", data);
        printf("queue get remain data len is %d \n", QueueGetTag(&sq));        
    }
    
    QueueDestroy(&sq);
    
    return;
}

int main(int argc, char**argv)
{
    queue_app_test();
    
    return 0;	
}
