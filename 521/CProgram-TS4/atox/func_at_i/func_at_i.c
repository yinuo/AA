/* function */

#include <stdio.h>
#include <stdlib.h>
 
int main( int argc, char ** argv)
{
    int idata  = 0;
    float fdata  = 0;
    long ldata = 0;
    if(argc > 1)
    {
        argv ++;
        idata = atoi(*argv);
        fdata = atof(*argv);
        ldata = atol(*argv);
        printf("get string is %s and value (int) is %d\n", (char*)*argv, idata);
        printf("value (float) is %f and value (long) is %d\n", fdata, (int)ldata);
    }
    return 0;
}
