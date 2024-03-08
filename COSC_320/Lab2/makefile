PROG = Lab_2
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Lab02.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

Lab02.o : Lab02.cpp
	$(CC) $(CPPFLAGS) -c Lab02.cpp binSearch.h deSelSort.h 

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make