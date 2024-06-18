
#ifndef LIST_PROJECT_SORTED_DOUBLE_LINKED_LIST_H
#define LIST_PROJECT_SORTED_DOUBLE_LINKED_LIST_H


#include "dlinkedlist.h"
#include "comparable.h"

/**
 * Note that there are only two methods for this class
 * The constructor is not going to do anything
 * And Insert is overridden without position, as it is supposed
 * to insert in such a way that the list is always sorted.
 */

class SortedDoubleLinkedList : public DoubleLinkedList {
public:
    SortedDoubleLinkedList();
    virtual bool Insert(Comparable* element);
};


#endif //LIST_PROJECT_SORTED_DOUBLE_LINKED_LIST_H
