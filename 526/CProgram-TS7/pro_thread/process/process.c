/* process.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int child_count = 0;
int parent_count = 0;

/*************************************************************************
 * \child process
 *************************************************************************/
void child_process()
{
    printf("Child process id is %d\n", getpid());
    
    while(1)
    {
    	  printf(" @C@: Child process child_count is %d\n", child_count);
    	  printf(" @C@: Parent process parent_count is %d\n", parent_count);
    	  printf("\n");
    	      	  
    	  child_count++;
    	  
    		sleep(2);
    }
}

//////////////////////////////////////////////////////////////////////////
/*************************************************************************
 * \brief main
 *************************************************************************/
int main(int argc, char* argv[])
{
    pid_t pid;

    pid = fork();
    
    if (pid == 0)
    {
        child_process();
    }
    else
    {
    	  printf("Parent process id is %d\n", getpid());
    	  
        while(1)
        {
    	      printf(" @P@: Child process child_count is %d\n", child_count);
    	      printf(" @P@: Parent process parent_count is %d\n", parent_count);
    	      printf("\n");
    	      
    	      parent_count++;
    	      
    		    sleep(3);
        }
    }
    
    return 0;
}
