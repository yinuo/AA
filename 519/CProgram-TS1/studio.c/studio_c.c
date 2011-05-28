/* studio */

#include <stdio.h>

int main( int argc, char ** argv)
{
    char ch_d = 0;
    
    ch_d = 127;
    printf("ch_d value is %d (127)\n",  ch_d);
    ch_d = 128;   // overflow
    printf("ch_d value is %d (128)\n",  ch_d);
    ch_d = -128;
    printf("ch_d value is %d (-128)\n",  ch_d);
    ch_d = -129;  // underflow
    printf("ch_d value is %d (-129)\n",  ch_d);   
     
    return 0;
}
