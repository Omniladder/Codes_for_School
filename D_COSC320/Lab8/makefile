PROG = Lab08
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Lab08.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

Lab08.o : Lab08.cpp
	$(CC) $(CPPFLAGS) -c Lab08.cpp preqrec.h d_pqueue.h d_heap.h d_except.h

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make