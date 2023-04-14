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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This is the database component to the bank database
//   application, which handles the methods used to
//   add, print, find, and delete records within the
//   database.
//
 ****************************************************************/

#include "llist.h"
#include <iostream>
#include <string.h>

extern int debugmode;

llist::llist()
{
    this->start = NULL;
    strncpy(this->filename, "database.txt", 20);
}

llist::llist(char filename[])
{
    this->start = NULL;
    strncpy(this->filename, filename, 20);
}

llist::~llist()
{
}

void llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
}

int llist::findRecord(int uaccountno)
{
    return 1;
}

void llist::printAllRecords()
{
}

int llist::deleteRecord(int uaccountno)
{
    return 1;
}

int llist::writefile()
{
    return 1;
}

int llist::readfile()
{
    return 1;
}

void llist::cleanup()
{
}