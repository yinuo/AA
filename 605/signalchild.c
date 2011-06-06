#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 
#include <sys/wait.h> 

/*
exit函数参数
0操作成功完成。   
1功能错误。   
2系统找不到指定的文件。 
3系统找不到指定的路径。   
4系统无法打开文件。   
5拒绝访问。   
6句柄无效。   
7存储控制块被损坏
*/
void handler(int num) 
{ 
	//接收到SIGCHLD
	int status; 
	int pid = waitpid(-1, &status, WNOHANG); 
	if (WIFEXITED(status)) { 
		printf("The child %d exit with code %d\n", pid, WEXITSTATUS(status)); 
	} 
} 

int main() 
{ 
	//子进程的pid 
	int c_pid; 
	int pid; 
	int i;

	signal(SIGCHLD, handler); 

	if ((pid = fork())) 
	{ 
		//父进程 
		c_pid = pid; 
		printf("The child process is %d\n", c_pid); 

		//父进程不等待，做自己的事情
		for (i = 0; i < 10; i++) 
		{ 
			printf("Do parent things.\n"); 
			sleep(1); 
		} 

		exit(0); 
	} 
	else 
	{ 
		//子进程 
		printf("I 'm a child.\n"); 
		sleep(2); 
		exit(2); 
	} 
}
