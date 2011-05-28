/* func_file_f.c */

#include <stdio.h>

int main (int argc, char** argv)
{
    FILE * pFile;
    char buf[] = "hello file";
    char dbuf[128] = {0};

    pFile = fopen ("file_f.txt","w+");
    if (pFile!=NULL)
    {
        fwrite (buf , 1 , sizeof(buf) , pFile );
        fseek(pFile, 2, SEEK_SET);
        fread (dbuf, 1, sizeof(buf) - 5, pFile);
        printf(" fread (len %d) string is <%s>\n", sizeof(buf) - 5, dbuf);
        fclose (pFile);
    }
    return 0;
}
