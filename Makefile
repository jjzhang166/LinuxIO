.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=dup_dup dup_dup1 fcntl_dup redirect redirect_dup2
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
