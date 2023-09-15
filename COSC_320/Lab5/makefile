PROG = lab_05
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = lab_05.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

lab_05.o : lab_05.cpp
	$(CC) $(CPPFLAGS) -c lab_05.cpp d_stree.h d_except.h d_random.h d_stiter.h int.h

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make