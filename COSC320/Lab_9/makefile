PROG = Lab_09
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Lab_09.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

Lab_09.o : lab_09.cpp
	$(CC) $(CPPFLAGS) -c lab_09.cpp 

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make