#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void tcp_client(){





}


int main(int argc, char* argv[])
{
   
    
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

