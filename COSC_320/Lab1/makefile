PROG = Lab_1
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Lab01.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

Lab01.o : Lab01.cpp
	$(CC) $(CPPFLAGS) -c Lab01.cpp deSelSort.h

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make