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
using namespace std;

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
    struct record *cursor = this->start;
    int success = 1;

    if (debugmode == 1)
    {
        cout << "** START * findRecord **" << endl;
        cout << "* uaccountno: " << uaccountno << endl;
        cout << "**  END  * findRecord **" << endl;
    }

    while (cursor != NULL)
    {
        if (uaccountno == cursor->accountno)
        {
            cout << "#  Account: " << cursor->accountno << endl;
            cout << "#>    Name: " << cursor->name << endl;
            cout << "#> Address: " << cursor->address << endl;
            success = 0;
        }
        cursor = cursor->next;
    }

    return success;
}

void llist::printAllRecords()
{
    struct record *cursor = this->start;

    if (debugmode == 1)
    {
        cout << "** START * printAllRecords **" << endl;
    }

    while (cursor != NULL)
    {
        cout << "#  Account: " << cursor->accountno << endl;
        cout << "#>    Name: " << cursor->name << endl;
        cout << "#> Address: " << cursor->address << endl;
        cursor = cursor->next;
    }

    if (debugmode == 1)
    {
        cout << "**  END  * printAllRecords **" << endl;
    }
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