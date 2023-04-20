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
#include <cstring>

using namespace std;

extern int debugmode;

llist::llist()
{
    if (debugmode == 1)
    {
        cout << "** START * llist **" << endl;
        cout << "* filename: " << "database.txt" << endl;
        cout << "**  END  * llist **" << endl;
    }

    this->start = NULL;
    this->readfile();
    strncpy(this->filename, "database.txt", 20);
}

llist::llist(char filename[])
{
    if (debugmode == 1)
    {
        cout << "** START * llist **" << endl;
        cout << "* filename: " << filename << endl;
        cout << "**  END  * llist **" << endl;
    }

    this->start = NULL;
    this->readfile();
    strncpy(this->filename, filename, 20);
}

// copy constructor
llist::llist(const llist &list)
{
    this->start = list.start;
    strncpy(this->filename, list.filename, 20);
}

llist& llist::operator=(const llist& list)
{
    // operator overloading


    // copy calls llist's copy constructor
    llist copy(list);
    return *this;
}

//ostream& operator<<(ostream &stream, const llist &list)
//{
//    return;
//}

// destructor
llist::~llist()
{
    if (debugmode == 1)
    {
        cout << "** START * ~llist **" << endl;
        cout << "* called destructor " << endl;
        cout << "**  END  * ~llist **" << endl;
    }

    writefile();
    cleanup();
}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   This function adds a record into the database.
//
//  Parameters:    uaccountno (int) : The account number to add.
//                 uname (char[]) : The account name to add.
//                 uaddress (char[]) : The account address to add.
//
//  Return values:  void
//
 ****************************************************************/

void llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    struct record * newAccount = new struct record;

    if (debugmode == 1)
    {
        cout << "START * addRecord **" << endl;
        cout << "* uaccountno: " << uaccountno << endl;
        cout << "*      uname: " << uname << endl;
        cout << "*   uaddress: " << uaddress << endl;
        cout << "**  END  * addRecord **" << endl;
    }

    newAccount->accountno = uaccountno;
    strncpy(newAccount->name, uname, 30);
    strncpy(newAccount->address, uaddress, 50);
    newAccount->next = NULL;

    if (this->start == NULL)
    {
        /** Add record at empty head */
        this->start = newAccount;
    }
    else if (uaccountno < this->start->accountno)
    {
        /** Add record at head with at least one item. */
        struct record * temp = NULL;
        temp = this->start;
        this->start = newAccount;
        this->start->next = temp;
    }
    else
    {
        /** Add record somewhere else with at least one item. */

        struct record * cursor = this->start->next;
        struct record * precursor = this->start;

        while ( cursor != NULL && uaccountno > cursor->accountno)
        {
            cursor = cursor->next;
            precursor = precursor->next;
        }

        precursor->next = newAccount;
        newAccount->next = cursor;
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   This function finds a record from the database,
//                 given an account number.
//
//  Parameters:    uaccountno (int) : The account number to delete
//
//  Return values:  0 : success
//                  1 : error
//
 ****************************************************************/

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

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   This function prints all records stored on the
//                 database.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

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

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   This function deletes a record from the database,
//                 given an account number.
//
//  Parameters:    uaccountno (int) : The account number to delete
//
//  Return values:  0 : success
//                  1 : error
//
 ****************************************************************/

int llist::deleteRecord(int uaccountno)
{

    struct record * cursor = this->start;
    struct record * precursor;
    struct record * postcursor;
    int deleted = 1;

    if (debugmode == 1)
    {
        cout << "** START * deleteRecord **" << endl;
        cout << "* uaccountno: " << uaccountno << endl;
        cout << "**  END  * deleteRecord **" << endl;
    }

    while (cursor != NULL)
    {
        if (uaccountno == cursor->accountno)
        {
            deleted = 0;
            if (cursor == this->start)
            {
                this->start = cursor->next;
                cursor->next = NULL;
                delete cursor;
                cursor = this->start;
            }
            else
            {
                postcursor = cursor->next;
                cursor->next = NULL;
                delete cursor;
                precursor->next = postcursor;
                cursor = postcursor;
            }
        }
        else
        {
            precursor = cursor;
            cursor = cursor->next;
        }
    }

    return deleted;
}

int llist::writefile()
{
    return 1;
}

int llist::readfile()
{
    // ifstream var (file name)
    // check if open
    // check if good
    return 1;
}

void llist::cleanup()
{
}
