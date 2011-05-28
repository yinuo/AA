/* function */

#include <stdio.h>

void func_before( void)
{
     printf("@@: using before function!!! \n");
}

int main( int argc, char ** argv)
{
    func_before();
    return 0;
}
