/* studio */

#include <stdio.h>

int main( int argc, char ** argv)
{
    printf("char length is %d bytes\n",  sizeof(char));
    printf("short length is %d bytes\n",  sizeof(short));
    printf("int length is %d bytes\n",  sizeof(int));
    printf("float length is %d bytes\n",  sizeof(float));
    printf("double length is %d bytes\n",  sizeof(double));
    printf("long length is %d bytes\n",  sizeof(long));
    printf("long long length is %d bytes\n",  sizeof(long long));

    return 0;
}

