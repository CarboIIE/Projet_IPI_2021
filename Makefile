CC=gcc -Wall

all: prog

interface.o: interface.h board.h stack.h
main.o: interface.h board.h stack.h
board.o: board.h stack.h
stack.o: stack.h

prog: interface.o main.o board.o stack.o
	$(CC) -o $@ $^

clean:
	rm -f *.o *~
