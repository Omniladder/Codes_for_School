#include "d_pqueue.h" 
#include "preqrec.h"
#include <ctime>
#include <cstdlib>
using namespace std;  int main(){srand(time(NULL)); miniPQ<procReqRec> mpq;procReqRec record1("Process A",(rand()%40));procReqRec record2("Process B",(rand()%40));procReqRec record3("Process C",(rand()%40));procReqRec record4("Process D",(rand()%40));procReqRec record5("Process E",(rand()%40));procReqRec record6("Process F",(rand()%40));procReqRec record10("Process G",(rand()%40));procReqRec record7("Process H",(rand()%40));procReqRec record8("Process I",(rand()%40));procReqRec record9("Process J",(rand()%40));mpq.push(record1);mpq.push(record2);mpq.push(record3);mpq.push(record4);mpq.push(record5);mpq.push(record6);mpq.push(record7);mpq.push(record8);mpq.push(record9);mpq.push(record10);while(!mpq.empty()){cout<<mpq.top()<<endl;mpq.pop();}} //Does the assignment
