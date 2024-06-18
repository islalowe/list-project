
#ifndef LIST_PROJECT_VSARRAY_H
#define LIST_PROJECT_VSARRAY_H

#include "object.h"
#include "list.h"
#include <string>
using std::string;

class VSArray : public List{
    Object** _data;
    size_t _capacity;
    double _delta;
    VSArray(const VSArray&);
    const VSArray& operator=(const VSArray&);
    void Resize();
public:
    VSArray(size_t capacity, double increasePercentage = 0.5);
    virtual ~VSArray();
    virtual bool Insert(Object* element, size_t position);
    virtual int IndexOf(const Object* element)const;
    virtual Object* Remove(size_t position);
    virtual Object* Get(size_t position)const;
    virtual string ToString()const;
    virtual void Clear();
    size_t GetCapacity()const;

};


#endif //LIST_PROJECT_VSARRAY_H
