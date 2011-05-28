/* efficent optimize */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
    long long iloop = 8000000;
    char pswd[] = "china region 123456 beijing region 123456";
    long long time = 0;
    struct timeval *tv;
    int len = 0;
	// int len_num = strlen(pswd);
	  int checksum = 0;
	  
    tv = (struct timeval*)malloc(sizeof(struct timeval)); 
	  
    gettimeofday(tv, NULL);
    time = tv->tv_sec;
    while(iloop--)
    {
      #if 1                                        // About 3 seconds
        for(len=0; len<strlen(pswd); len++)
        {
            checksum += *(int*)((int)pswd + len);
        }
      #else                                        // About 1 seconds
        for(len=0; len<len_num; len++)
        {
            checksum += *(int*)((int)pswd + len);
        }      
      #endif
	  }
    gettimeofday(tv, NULL);
    printf(" Run time is %d s \n", (int)abs(tv->tv_sec - time));
    
    free(tv);
    	  
	  return 0;
}
