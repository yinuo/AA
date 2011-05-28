CROSS	= 
CC	= $(CROSS)gcc
LD	= $(CROSS)ld
AR	= $(CROSS)ar
RANLIB  = $(CROSS)ranlib
STRIP   = $(CROSS)strip

CFLAGS  = -Wall -Wshadow -Wno-trigraphs -pipe
LDFLAGS = -lm 

BIN		  = func_file_s
SRCS		= $(BIN).c
OBJS		= $(SRCS:.c=.o)

all: $(BIN)

$(OBJS): %.o: %.c
	$(CC) -c -g $(CFLAGS) $< -o $@

$(BIN): $(OBJS)
	$(CC) -lm $(OBJS) $(LDLIBS) -o func_file_s
#	$(STRIP) func_file_s
	
clean:
	rm -rf *.o
	rm -rf $(BIN)
	rm -rf *.o *.bak *.c.bak *.txt
