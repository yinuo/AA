#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char **argv){

	int result;
	struct stat buf;
	
	result = stat("1.c",&buf);
	
	if(result != 0)
      	 perror("Problem getting information");
   	 else
    	{
		printf("File size     : %c\n", buf.st_mode);
       		printf("File size     : %ld\n", buf.st_size);
       		printf("Drive         : %c:\n", buf.st_dev + 'A');
       		printf("Time modified : %s", ctime( &buf.st_atime));
    	}
	
	return 0;

}
