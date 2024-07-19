# list-project
Project implementing list ADT - using arrays, doubly linked lists, and sorting

## Description
This project implements a List Abstract Data Type (ADT) using both arrays and doubly linked lists. It includes a virtual parent class Object which can be derived into either a Person or Integer. The project features sorting functionality for a doubly linked list based on object types, as well as a comprehensive set of tests to ensure the correctness of the implementations.

## Features
Array-based List Implementation
Doubly Linked List Implementation
Sorting of Doubly Linked Lists
Virtual Parent Class Object
Derived classes: Person and Integer
Comprehensive Unit Tests

# Code Overview

## Comparable Class
A class providing a string representation of a general comparable object.

## DoubleLinkedList Class
A class implementing a doubly linked list with methods for deep copying, insertion, deletion, searching, and clearing.

## Integer Class
The Integer class is derived from the Object class and represents an integer value.

## Object Class
The Object class is an abstract base class that provides a common interface for all objects.

## Person Class
The Person class is derived from the Object class and represents a person with a name and age.

## SortedDoubleLinkedList
The SortedDoubleLinkedList class extends the DoubleLinkedList class to maintain a sorted order of elements.

## VSArray
The VSArray class implements a dynamically resizing array-based list.


## Building The Project
g++ -o list_project main.cpp object.cpp comparable.cpp dlinkedlist.cpp vsarray.cpp person.cpp integer.cpp sorted_double_linked_list.cpp

## Running Tests
./list_project -grade
