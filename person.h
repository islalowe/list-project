
#ifndef LIST_PROJECT_PERSON_H
#define LIST_PROJECT_PERSON_H

#include "comparable.h"
#include <string>
using std::string;

class Person : public Comparable{
    char* _name;
    size_t _age;
public:
    Person(const string& name, size_t age);
    Person(const Person& person);
    const Person& operator=(const Person& rhs);
    virtual ~Person();
    virtual string ToString()const;
    virtual bool Equals(const Object& rhs)const;
    virtual Object* Clone()const;
    void Birthday();
    virtual int CompareTo(const Comparable* rhs)const;
};


#endif //LIST_PROJECT_PERSON_H
