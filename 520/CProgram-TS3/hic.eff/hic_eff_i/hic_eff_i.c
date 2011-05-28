/* efficent optimize */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#if 1                            // About < 10 u seconds
inline int inline_test(void)
#else                              // About > 200000 u seconds
int inline_test(void)
#endif 	 
{
    long long kloop = 0;
    	
    char a[2000000] = {0};
    char b[2000000] = {0};
        	
    for(kloop=0; kloop < 2; kloop++)
    {
        a[kloop] = b[kloop];
    }
    
    while(kloop--){};  
    
    return 0;
}

int main(int argc, char** argv)
{
    long long iloop = 8000;
    long long time = 0;
    struct timeval *tv;
	  
    tv = (struct timeval*)malloc(sizeof(struct timeval)); 
	  
    gettimeofday(tv, NULL);
    time = tv->tv_usec;
    
    while(iloop--)
    {
        inline_test();                   
	  }
	  
    gettimeofday(tv, NULL);
    printf(" Run time is %d us \n", (int)abs(tv->tv_usec - time));
    
    free(tv);
    	  
	  return 0;
}
