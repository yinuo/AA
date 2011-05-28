/* efficent optimize */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
    long long iloop = 8000;
    long long kloop = 0;
    char a[200000] = {0};
    char b[200000] = {0};
    long long time = 0;
    struct timeval *tv;
	  
    tv = (struct timeval*)malloc(sizeof(struct timeval)); 
	  
    gettimeofday(tv, NULL);
    time = tv->tv_sec;
    
    while(iloop--)
    {
#if 0                              // About 10 seconds
        for(kloop=0; kloop < 200000; kloop++)
        {
            a[kloop] = b[kloop];
        }
#else                              // About 6 seconds
        for(kloop=0; kloop < 200000; kloop+=4)
        {
            a[kloop] = b[kloop];
            a[kloop+1] = b[kloop+1];
            a[kloop+2] = b[kloop+2];
            a[kloop+3] = b[kloop+3];
}

       
#endif 	      	      	       	         
	  }
	  
    gettimeofday(tv, NULL);
    printf(" Run time is %d s \n", (int)abs(tv->tv_sec - time));
    
    free(tv);
    	  
	  return 0;
}
