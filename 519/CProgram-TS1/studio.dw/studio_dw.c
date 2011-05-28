/* studio */

#include <stdio.h>

int main( int argc, char ** argv)
{  
    unsigned int iloop = 0;
    
    do 
    {
        printf("do while run step is %d \n",  iloop);
        iloop ++;
    } while(iloop <= 8);

    return 0;
}
