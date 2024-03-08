PROG = Project2
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp miniArrayQueue.h miniArrayStack.h miniDList.h miniDListQueue.h miniDListStack.h RuntimeException.h

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
