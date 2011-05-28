/* func_math_f.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char**argv)
{
    float x;
    
    x = -74.12;
    printf("|%f| = %f(fabs) : %f(abs)\n", x, fabs(x), (float)abs(x));
    x = 0.0;
    printf("|%f| = %f(fabs) : %f(abs)\n", x, fabs(x), (float)abs(x));
    x = 74.12;
    printf("|%f| = %f(fabs) : %f(abs)\n", x, fabs(x), (float)abs(x));
    
    return 0;
}
