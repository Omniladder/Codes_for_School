PROG = Lab3
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o CustomerData.o PersonData.o PreferredCustomer.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

CustomerData.o : CustomerData.h CustomerData.cpp
	$(CC) $(CPPFLAGS) -c CustomerData.cpp

PersonData.o : PersonData.h PersonData.cpp
	$(CC) $(CPPFLAGS) -c PersonData.cpp

PreferredCustomer.o : PreferredCustomer.h PreferredCustomer.cpp
	$(CC) $(CPPFLAGS) -c PreferredCustomer.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
