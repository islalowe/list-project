cmake_minimum_required(VERSION 3.22)
project(list_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(list_project
        object.cpp
        object.h
        comparable.h
        comparable.cpp
        list.h
        list.cpp
        dlinkedlist.h
        dlinkedlist.cpp
        integer.h
        integer.cpp
        person.h
        person.cpp
        sorted_double_linked_list.h
        sorted_double_linked_list.cpp
        test.cpp
        vsarray.cpp)

#CFLAGS = -std=c++14 -Wall -g
#CC = g++
#SOURCEDIR = .
#BUILDDIR = cmake-build-debug
#
#EXE = list
#SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
##SOURCES = $(SOURCEDIR)/*.cpp
#OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))
#
#all: dir $(BUILDDIR)/$(EXE)
#
#dir:
#mkdir -p $(BUILDDIR)
#
#$(BUILDDIR)/$(EXE):	$(OBJECTS)
#$(CC) $(CFLAGS) $^ -o $@
#
#$(OBJECTS):	$(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
#$(CC) $(CFLAGS) -c $< -o $@
#
#clean:
#rm -f $(BUILDDIR)/*.o $(BUILDDIR)/$(EXE)
#
#grade: all
#$(BUILDDIR)/list -grade
#
#grade-mem: all
#valgrind --leak-check=full $(BUILDDIR)/list -grade