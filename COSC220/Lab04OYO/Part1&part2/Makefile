PROG = Lab3
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o IntegerList.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

IntegerList.o : IntegerList.h IntegerList.cpp
	$(CC) $(CPPFLAGS) -c IntegerList.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
