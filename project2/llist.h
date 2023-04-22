/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 12, 2023
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   The class and function prototypes of the llist.cpp file.
//
 ****************************************************************/

#ifndef LLIST_H
#define LLIST_H
#include "record.h"
#include <ostream>

class llist
{
private:
    record *start;
    char filename[20];

    llist& operator=(const llist&);

    friend std::ostream& operator<<(std::ostream&, const llist&);

    int readfile();

    int writefile();

    void cleanup();

public:
    llist();

    llist(char[]);

    llist(const llist&);

    ~llist();

    void addRecord(int, char [], char []);

    int findRecord(int);

    void printAllRecords();

    int deleteRecord(int);
};
#endif