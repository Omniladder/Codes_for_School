PROG = Project_1
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o NumDays.o TimeOff.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

NumDays.o : NumDays.h NumDays.cpp
	$(CC) $(CPPFLAGS) -c NumDays.cpp

TimeOff.o : TimeOff.h TimeOff.cpp
	$(CC) $(CPPFLAGS) -c TimeOff.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
