/* #define DATA_TYPE */

#include <stdio.h>
#include <stdlib.h>

#define SECONDS_PER_YEAR_F 60 * 60 * 24 * 365.0F
#define SECONDS_PER_YEAR 60 * 60 * 24 * 365
#define SECONDS_PER_10_YEAR 60 * 60 * 24 * 365 *10UL
#define SECONDS_PER_100_YEAR 60 * 60 * 24 * 365 *100LL 

int main(int argc, char** argv)
{
    printf("sizeof(F) bytes len is %d \n", sizeof(SECONDS_PER_YEAR_F)); 	
    printf("sizeof(I) bytes len is %d \n", sizeof(SECONDS_PER_YEAR)); 	
    printf("sizeof(UL) bytes len is %d \n", sizeof(SECONDS_PER_10_YEAR));    
    printf("sizeof(LL) bytes len is %d \n", sizeof(SECONDS_PER_100_YEAR));
    
    printf("\nSECONDS_PER_YEAR_F is %f \n", SECONDS_PER_YEAR_F);  
    printf("SECONDS_PER_YEAR is %d \n", SECONDS_PER_YEAR);     
    printf("SECONDS_PER_10_YEAR is %ld \n", SECONDS_PER_10_YEAR);    
    printf("SECONDS_PER_100_YEAR is %lld \n", SECONDS_PER_100_YEAR);
    
	  return 0;
}
