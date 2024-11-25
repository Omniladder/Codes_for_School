#ifndef IOSTREAM_H
#define IOSTREAM_H 

using namespace std;

#include <iostream.h>


ostream&  operator<<(ostream &os){
	os << "Hello World";
	return os;
}


#endif
