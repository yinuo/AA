main:main.o tcp_client.o jiexi.o udp_client.o
	gcc main.o tcp_client.o jiexi.o udp_client.o -I. -Wall -o main
main.o:main.c
	gcc -c main.c
tcp_client.o:tcp_client.c
	gcc -c tcp_client.c

jiexi.o:jiexi.c
	gcc -c jiexi.c
udp_client.o:udp_client.c
	gcc -c udp_client.c
clean:
	-rm main *.o
.PHONY:clean
