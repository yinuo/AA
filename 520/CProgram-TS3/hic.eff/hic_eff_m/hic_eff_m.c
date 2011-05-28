/* efficent optimize */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
    long long iloop = 200000000;
    long long time = 0;
    struct timeval *tv;    
	  long long data = 8;
	  
    tv = (struct timeval*)malloc(sizeof(struct timeval)); 
	  
    gettimeofday(tv, NULL);
    time = tv->tv_sec;
    	  
	  while(iloop--)
	  {
#if 1                              // About 5 seconds
	      data = data >> 1;
	      data = data << 1;
	      data = data >> 1;
	      data = data << 1;
	      data = data >> 1;
	      data = data << 1;
	      data = data >> 1;
	      data = data << 1;	      	      	      
	      
#else                              // About 7 seconds
	      data = data / 2;
	      data = data * 2;
	      data = data / 2;
	      data = data * 2; 
	      data = data / 2;
	      data = data * 2; 
	      data = data / 2;
	      data = data * 2;
#endif 	      	      	       	         
	  }
	  
    gettimeofday(tv, NULL);
    printf(" Run time is %d s \n", (int)abs(tv->tv_sec - time));
    
    free(tv);
    	  
	  return 0;
}
