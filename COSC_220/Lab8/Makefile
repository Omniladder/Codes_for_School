PROG = Lab8_InLab
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp ListCollection.h Stack.h Queue.h

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
