/* process.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int process_count = 0;
int thread_count = 0;

/*************************************************************************
 * \thread
 *************************************************************************/
void * pro_thread(void *pPara)
{
	  while(1)
	  {
        printf(" @T@: Thread process_count is %d\n", process_count);
    	  printf(" @T@: Thread thread_count is %d\n", thread_count);
    	  printf("\n");
    	  
    	  thread_count++;
    	  
        sleep(3);
    }
}

//////////////////////////////////////////////////////////////////////////
/*************************************************************************
 * \brief main
 *************************************************************************/
int main(int argc, char* argv[])
{
    pthread_t p_mon;
    
    pthread_create(&p_mon, NULL, pro_thread, NULL);
    
    while(1)
    {
        printf(" @P@: Process process_count is %d\n", process_count);
    	  printf(" @P@: Process thread_count is %d\n", thread_count);
    	  printf("\n");
    	  
    	  process_count++;
    	  
    		sleep(2);
    }
    
    return 0;
}
