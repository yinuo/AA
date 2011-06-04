#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


int main(int argc,char **argv){

	int fd1,fd2;
	fd1 = open("file_f.txt",O_RDONLY);
	fd2 = open("2.txt",O_WRONLY | O_CREAT,00700);
	char dbuf[128] = {0};
   	
	while(read(fd1,dbuf,sizeof(dbuf))){;
	
	write(fd2,dbuf,sizeof(dbuf));
	 }	
	close(fd1);
	close(fd2);		

	return 0;
}
