
#ifndef LIST_PROJECT_INTEGER_H
#define LIST_PROJECT_INTEGER_H

#include "comparable.h"
#include <string>
using std::string;

class Integer : public Comparable{
    int _value;
public:
    Integer(int = 0);
    virtual string ToString()const;
    int GetValue()const;
    void SetValue(int);
    virtual bool Equals(const Object& rhs)const;
    virtual Object* Clone()const;
    virtual int CompareTo(const Comparable* rhs)const;
};

#endif //LIST_PROJECT_INTEGER_H
