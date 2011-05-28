/* func_file_s.c */

#include <stdio.h>
#include <string.h>

int main (int argc, char** argv)
{
    FILE * pFile;
    char dbuf[128] = {0}; 
    char sbuf[128] = {0};
    
    pFile = fopen ("file_f.txt", "w+");
    if (pFile != NULL)
    {
        printf ("Please Enter String: ");	  
        fgets (dbuf, 128, stdin);
        fputs (dbuf, pFile);
        printf(" ftell() get is <%d>\n", (int)ftell(pFile));
        fseek(pFile, -strlen(dbuf), SEEK_END);      
        fgets (sbuf, strlen(dbuf), pFile);
        printf(" fgets() string is <%s>\n", sbuf);        
        fclose (pFile);
    }
    return 0;
}
