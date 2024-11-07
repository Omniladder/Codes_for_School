PROG = Lab3
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Complex.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Complex.o : Complex.h Complex.cpp
	$(CC) $(CPPFLAGS) -c Complex.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
