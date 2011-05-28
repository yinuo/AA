/* efficent optimize */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX(x, y)    ((x>y)?x:y)
#define MIN(x, y)    ((x<y)?x:y)

#define USE_INLINE_EXTENDED

#ifdef USE_INLINE_EXTENDED
inline int max_calc(int x, int y)
#else
int max_calc(int x, int y)
#endif
{
    return((x>y)?x:y);	
}

#ifdef USE_INLINE_EXTENDED
inline int min_calc(int x, int y)
#else
int min_calc(int x, int y)
#endif
{
    return((x>y)?x:y);	
}

int main(int argc, char** argv)
{
    long long iloop = 800000000;
    long long time = 0;
    struct timeval *tv;
	  int max_d = 0;
	  int min_d = 0;
	  
    tv = (struct timeval*)malloc(sizeof(struct timeval)); 
	  
    gettimeofday(tv, NULL);
    time = tv->tv_sec;
    	  
	  while(iloop--)
	  {
#if 0                                // About 3 seconds
        max_d = MAX(0, 1);
        min_d = MIN(0, 1);
#else                                // About 9 seconds
        max_d = max_calc(0, 1);
        min_d = min_calc(0, 1);
#endif
	  }
	  
    gettimeofday(tv, NULL);
    printf(" Run time is %d s \n", (int)abs(tv->tv_sec - time));
    
    free(tv);
    
	  return 0;
}
