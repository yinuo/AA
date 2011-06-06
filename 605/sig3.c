#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){
	
	//char str[100] = {0};
	int sig2;
	pid_t sig1;
	union sigval val;
		sig2 = atoi(argv[2]);
	sig1 =(pid_t) atoi(argv[1]);

	while(1){
	//sprintf(str,"kill -s %s %s","sig1","sig2");
	sigqueue(sig1,sig2,val);
	//system(str);
	sleep(3);
	}



	//int sigqueue(pid_t pid, int sig, const union sigval val)





	return 0;
}
