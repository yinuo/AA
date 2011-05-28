/* func_file_e.c */

#include <stdio.h>
#include <string.h>

int main (int argc, char** argv)
{
     FILE * pFile;
     unsigned long num = 0;
     pFile = fopen ("file_f.txt", "r+");
     if (pFile != NULL)
     {
         while (!feof(pFile))
         {
             fgetc (pFile);
             num++;
         }

         fclose (pFile);
         printf ("Total number of bytes: %d\n", (int)num - 1);
     }
     return 0;
}
