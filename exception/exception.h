#ifndef TOL_EXCEPTION_H
#define TOL_EXCEPTION_H

#include <exception>

using namespace std;

class CustomException : public exception {
public:
    virtual void print() const = 0;
};



#endif //TOL_EXCEPTION_H
