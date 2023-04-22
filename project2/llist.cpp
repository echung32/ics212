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

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:    Initializes the linked list and reads the database
//                  file from the disk to restore the data.
//
//  Parameters:     void
//
//  Return values:  void
//
****************************************************************/

llist::llist()
{
    #ifdef DEBUG
    cout << "** START * llist **" << endl;
    cout << "* filename: " << "database.txt" << endl;
    cout << "**  END  * llist **" << endl;
    #endif

    this->start = NULL;
    this->readfile();
    strncpy(this->filename, "database.txt", 20);
}

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:    Initializes the linked list and reads the database
//                  file from the disk to restore the data.
//
//  Parameters:    filename (char[]) : The file name to read the data from.
//
//  Return values:  void
//
****************************************************************/

llist::llist(char filename[])
{
    #ifdef DEBUG
    cout << "** START * llist **" << endl;
    cout << "* filename: " << filename << endl;
    cout << "**  END  * llist **" << endl;
    #endif

    this->start = NULL;
    this->readfile();
    strncpy(this->filename, filename, 20);
}

/*****************************************************************
//
//  Function name:  llist
//
//  DESCRIPTION:    The copy constructor initializes the list and
//                  clones data from an existing list. This is used
//                  when setting an initially uninitialized list.
//
//  Parameters:     list (const llist&) : The list to copy data from.
//
//  Return values:  void
//
****************************************************************/

llist::llist(const llist &list)
{
    struct record *cursor = this->start;

    while (cursor != NULL)
    {
        this->addRecord(cursor->accountno, cursor->name, cursor->address);
        cursor = cursor->next;
    }

    strncpy(this->filename, list.filename, 20);
}

/*****************************************************************
//
//  Function name: operator=
//
//  DESCRIPTION:    The assignment operator replaces the current data
//                  with the data from the list that is passed in.
//                  This is called when setting an initialized list.
//
//  Parameters:     list (const llist&) : The list to copy data from.
//
//  Return values:  llist& : the list where the data was copied to
//
****************************************************************/

llist& llist::operator=(const llist& list)
{
    // Cleans up the existing data.
    this->cleanup();

    // Now, add the data from the passed in list.
    // This function calls the copy constructor to populate `this` list.
    llist copy(list);
    return *this;
}

/*****************************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   The insertion operator allows direct piping of
//                 the list class to display all the currently
//                 held records in the list.
//
//  Parameters:    stream (ostream&) : The output stream
//                 list (const llist&) : The list to print data from.
//
//  Return values:  ostream& : the output stream which holds the printed data.
//
 ****************************************************************/

ostream& operator<<(ostream &stream, const llist &list)
{
    struct record *cursor = this->start;

    while (cursor != NULL)
    {
        stream << "#  Account: " << cursor->accountno << endl;
        stream << "#>    Name: " << cursor->name << endl;
        stream << "#> Address: " << cursor->address << endl;
        cursor = cursor->next;
    }

    return stream;
}

/*****************************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   This function saves the list to disk and removes
//                 the list data from the heap.
//
//  Parameters:     void
//
//  Return values:  void
//
 ****************************************************************/

llist::~llist()
{
    #ifdef DEBUG
    cout << "** START * ~llist **" << endl;
    cout << "* called destructor " << endl;
    cout << "**  END  * ~llist **" << endl;
    #endif

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

    #ifdef DEBUG
    cout << "START * addRecord **" << endl;
    cout << "* uaccountno: " << uaccountno << endl;
    cout << "*      uname: " << uname << endl;
    cout << "*   uaddress: " << uaddress << endl;
    cout << "**  END  * addRecord **" << endl;
    #endif

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

    #ifdef DEBUG
    cout << "** START * findRecord **" << endl;
    cout << "* uaccountno: " << uaccountno << endl;
    cout << "**  END  * findRecord **" << endl;
    #endif

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
    int debugmode;

    #ifdef DEBUG
    debugmode = 1;
    #endif

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

    #ifdef DEBUG
    cout << "** START * deleteRecord **" << endl;
    cout << "* uaccountno: " << uaccountno << endl;
    cout << "**  END  * deleteRecord **" << endl;
    #endif

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
