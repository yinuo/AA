server:server.o tcp_server.o udp_server.o
	gcc server.o tcp_server.o udp_server.o -I. -Wall -o server
tcp_server.o:tcp_server.c
	gcc -c tcp_server.c
udp_server.o:udp_server.c
	gcc -c udp_server.c

clean:
	-rm tcp_server *.o
.PHONY:clean
