PROG = Lab7
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = ListCollection.o FeetInches.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

ListCollection.o : ListCollection.h ListCollection.cpp
	$(CC) $(CPPFLAGS) -c ListCollection.cpp
FeetInches.o : FeetInches.h FeetInches.cpp
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
