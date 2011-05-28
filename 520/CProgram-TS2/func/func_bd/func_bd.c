/* function */

#include <stdio.h>

void func_behind( void);

int main( int argc, char ** argv)
{
    func_behind();
    return 0;
}

void func_behind( void)
{
     printf("@@: using behind function!!! \n");
}
