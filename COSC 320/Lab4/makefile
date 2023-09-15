PROG = lab_04
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = lab_04.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

lab_04.o : lab_04.cpp
	$(CC) $(CPPFLAGS) -c lab_04.cpp d_tnode.h d_tnodel.h 

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make