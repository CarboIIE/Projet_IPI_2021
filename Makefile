CC=gcc -Wall

all: prog

interface.o: interface.h board.h stack.h
main.o: interface.h board.h stack.h
#main_test.o: interface.h board.h stack.h #ligne a supprimer plus tard
board.o: board.h stack.h
stack.o: stack.h
#square_list.o: square_list.h board.h

prog: interface.o main.o board.o stack.o
	$(CC) -o $@ $^

clean:
	rm -f *.o *~
