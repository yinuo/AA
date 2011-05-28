#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "udp_server.h"
#include "tcp_server.h"

int main(int argc, char* argv[])
{
    pid_t pid;

    pid = fork();
    
    if (pid == 0)
    {
        udp_server();
    }
    else
    {
	tcp_server();
    }
    
    return 0;
}
