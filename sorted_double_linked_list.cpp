
#include "sorted_double_linked_list.h"
#include "person.h"
#include "integer.h"


/**
 * Constructor that doesn't do anything else
 */
SortedDoubleLinkedList::SortedDoubleLinkedList() {
}


bool SortedDoubleLinkedList::Insert(Comparable *element) {
    bool inserted = false;
    Node* neo = new Node;
    neo -> data = element;
    neo -> next = nullptr;
    neo -> previous = nullptr;

    // case 1: empty list
    if (_size == 0) {
        _head = neo;
        _tail = neo;
        inserted = true;
    }
    else {
        Node* tmp = _head;

        //iteration happens separately but whether data is a person or integer it will scoot up once if it needs to
        if (dynamic_cast<Person*>(element) != nullptr) {
            // If the current node points to a person
            while (tmp && dynamic_cast<Person*>(tmp->data)->CompareTo(element) < 0) {
                tmp = tmp -> next;
            }
        }
        else if (dynamic_cast<Integer*>(element) != nullptr) {
            // If the current node points to an integer
            while (tmp && dynamic_cast<Integer*>(tmp->data)->CompareTo(element) < 0) {
                tmp = tmp -> next;
            }
        }

        //at the beginning
        if (tmp == _head) {
            neo -> next = _head;
            _head -> previous = neo;
            _head = neo;
        }
            //at the end
        else if (tmp == nullptr) {
            neo -> previous = _tail;
            _tail -> next = neo;
            _tail = neo;
        }
            //in the middle using tmp
        else {
            neo -> next = tmp;
            neo -> previous = tmp -> previous;
            tmp -> previous -> next = neo;
            tmp -> previous = neo;
        }
        inserted = true;
    }
    _size++;
    return inserted;
}
