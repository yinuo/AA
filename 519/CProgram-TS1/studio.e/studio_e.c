/* studio */

#include <stdio.h>
#include "enum_e.h"

int main( int argc, char ** argv)
{
    unsigned int cmd = 0;

    cmd = FILE_OPEN ;
    if(cmd  == FILE_OPEN)
    {
        printf("FILE_OPEN (cmd alue is %d) and FILE_CLOSE (cmd value is %d) \n", FILE_OPEN, FILE_CLOSE);
    }
    
    return 0;
}
