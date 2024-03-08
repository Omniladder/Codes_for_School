#ifndef RUNTIMEEXCEPTION_H
#define RUNTIMEEXCEPTION_H

#include <string>
using namespace std;
class RuntimeException{
    private:
      string errorMsg;
    public:
      RuntimeException(const string& err){errorMsg=err;}
      string getMessage() const {return errorMsg;}
};

class StackEmpty : public RuntimeException{
public:
    StackEmpty(const string& err):RuntimeException(err){}
};

class StackFull : public RuntimeException{
public:
    StackFull(const string& err):RuntimeException(err){}
};

class QueueEmpty : public RuntimeException{
public:
    QueueEmpty(const string& err):RuntimeException(err){}
};

class QueueFull : public RuntimeException{
public:
    QueueFull(const string& err):RuntimeException(err){}
};

#endif
