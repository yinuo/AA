#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){



void handler(int num) 
{ 
	int status; 
	int pid = waitpid(-1, &status, WNOHANG); //WNOHANG父进程立即返回当没有子进程存在时
	if (WIFEXITED(status)) { //WIFEXITED判断子进程推出值是非0
		printf("The child %d exit with code %d\n", pid, WEXITSTATUS(status)); 
	} 
} 

int main() 
{ 
	int c_pid; 
	int pid; 
	int i;

	signal(SIGCHLD, handler); 

	if ((pid = fork())) 
	{ 
		c_pid = pid; 
		//printf("The child process is %d\n", c_pid); 

		//for (i = 0; i < 10; i++) 
		//{ 
		//	printf("Do parent things.\n"); 
		//	sleep(1); 
		//}
		execl("sig1.c", "echo", "executed by execl", NULL)

		exit(0); 
	} 
	else 
	{ 
		printf("I 'm a child.\n"); 
		sleep(2); 
		exit(2); 
	} 
	return 0;
}




