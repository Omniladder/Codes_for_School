PROG = Project_1
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Course.o student.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Course.o : Course.h Course.cpp
	$(CC) $(CPPFLAGS) -c Course.cpp

student.o : student.h student.cpp
	$(CC) $(CPPFLAGS) -c student.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
