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
#include <fstream>

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
    strncpy(this->filename, "database.txt", 19);
    this->readfile();
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
    strncpy(this->filename, filename, 19);
    this->readfile();
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
    #ifdef DEBUG
    cout << "** START * llist (copy) **" << endl;
    cout << "* filename: " << list.filename << endl;
    cout << "**  END  * llist (copy) **" << endl;
    #endif

    struct record *cursor = list.start;

    this->start = NULL;
    /**
     * This should not be hardcoded to "copy-db.txt",
     * but since function parmeters cannot be modified
     * without approval, this is set to another file
     * to prevent write collisions with the default
     * `database.txt` file.
     */
    strncpy(this->filename, "copy-db.txt", 19);

    while (cursor != NULL)
    {
        this->addRecord(cursor->accountno, cursor->name, cursor->address);
        cursor = cursor->next;
    }
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
    #ifdef DEBUG
    cout << "** START * llist (assignment) **" << endl;
    cout << "* filename: " << list.filename << endl;
    cout << "**  END  * llist (assignment) **" << endl;
    #endif

    struct record *cursor = list.start;
    /**
     * This should not be hardcoded to "assign-db.txt",
     * but since function parmeters cannot be modified
     * without approval, this is set to another file
     * to prevent write collisions with the default
     * `database.txt` file.
     */
    strncpy(this->filename, "assign-db.txt", 19);

    // reset the list data here
    this->cleanup();

    while (cursor != NULL)
    {
        this->addRecord(cursor->accountno, cursor->name, cursor->address);
        cursor = cursor->next;
    }

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
    struct record *cursor = list.start;

    if (cursor == NULL)
    {
        stream << "# No records have been added!" << endl;
    }
    else
    {
        while (cursor != NULL)
        {
            stream << "#  Account: " << cursor->accountno << endl;
            stream << "#>    Name: " << cursor->name << endl;
            stream << "#> Address: " << cursor->address << endl;
            cursor = cursor->next;
        }
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
    cout << "* called destructor for " << this->filename << endl;
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
    cout << "** START * addRecord **" << endl;
    cout << "* uaccountno: " << uaccountno << endl;
    cout << "*      uname: " << uname << endl;
    cout << "*   uaddress: " << uaddress << endl;
    cout << "**  END  * addRecord **" << endl;
    #endif

    newAccount->accountno = uaccountno;
    strncpy(newAccount->name, uname, 29);
    strncpy(newAccount->address, uaddress, 49);
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
    #ifdef DEBUG
    cout << "** START * printAllRecords **" << endl;
    cout << *this;
    cout << "**  END  * printAllRecords **" << endl;
    #else
    cout << *this;
    #endif
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

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   called once after the user chooses the quit option.
//                 It saves the records into a file.
//
//  Parameters:    void
//
//  Return values:  0 : file written successfully
//                  1 : file was not written to successfully
//
 ****************************************************************/

int llist::writefile()
{
    int success = 1;
    ofstream ofile(this->filename, ifstream::out);

    /**
     * Ideally, the logic of the open should not be duplicated.
     * Since we cannot create helper methods without approval,
     * the code is being duplicated instead.
     */
    #ifdef DEBUG
    cout << "** START * writefile **" << endl;
    cout << "* filename: " << this->filename << endl;
    if (ofile.is_open())
    {
        struct record * cursor = start;

        while (cursor != NULL)
        {
            ofile << cursor->accountno << endl;
            ofile << cursor->name << endl;
            ofile << cursor->address << flush;
            ofile << "~" << flush;

            cout << "* writing account " << cursor->accountno << endl;

            cursor = cursor->next;
        }

        ofile.close();
        success = 0;
    }

    cout << "**  END  * writefile **\n" << endl;
    #else
    if (ofile.is_open())
    {
        struct record * cursor = start;

        while (cursor != NULL)
        {
            ofile << cursor->accountno << endl;
            ofile << cursor->name << endl;
            ofile << cursor->address << flush;
            ofile << "~" << flush;

            cursor = cursor->next;
        }

        ofile.close();
        success = 0;
    }
    #endif

    return success;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   called once before the program starts interacting with the user.
//                 It retrieves the records from the saved file.
//
//  Parameters:    void
//
//  Return values:  0 : file read successfully
//                  1 : file was not read successfully
//
 ****************************************************************/

int llist::readfile()
{
    int success = 1;
    ifstream ofile(this->filename, ifstream::in);

    /**
     * Ideally, the logic of the open should not be duplicated.
     * Since we cannot create helper methods without approval,
     * the code is being duplicated instead.
     */
    #ifdef DEBUG
    cout << "** START * readfile **" << endl;
    cout << "* filename: " << this->filename << endl;
    if (ofile.is_open())
    {
        // peek to make sure file isn't at eof
        // ofile.eof() still continues to read anyways.
        while (ofile.good() && ofile.peek() != ifstream::traits_type::eof())
        {
            int accountno;
            char name[30];
            char address[50];

            ofile >> accountno;
            ofile.ignore(1000, '\n'); // get rid of leftover newline
            ofile.getline(name, 30, '\n');
            ofile.getline(address, 51, '~');

            cout << "* reading account " << accountno << endl;

            this->addRecord(accountno, name, address);
        }

        ofile.close();
        success = 0;
        cout << "**  END  * readfile **\n" << endl;
    }
    #else
    if (ofile.is_open())
    {
        // peek to make sure file isn't at eof
        // ofile.eof() still continues to read anyways.
        while (ofile.good() && ofile.peek() != ifstream::traits_type::eof())
        {
            int accountno;
            char name[30];
            char address[50];

            ofile >> accountno;
            ofile.ignore(1000, '\n'); // get rid of leftover newline
            ofile.getline(name, 30, '\n');
            ofile.getline(address, 51, '~');

            this->addRecord(accountno, name, address);
        }

        ofile.close();
        success = 0;
    }
    #endif

    return success;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   called at the end. It releases all the allocated
//                 spaces in the heap memory and assign NULL to start.
//
//  Parameters:     void
//
//  Return values:  void
//
 ****************************************************************/

void llist::cleanup()
{
    struct record * cursor = this->start;
    struct record * postcursor;
    this->start = NULL;

    #ifdef DEBUG
    cout << "** START * cleanup **" << endl;
    while (cursor != NULL)
    {
        cout << "* cleaning account " << cursor->accountno << endl;
        postcursor = cursor->next;
        cursor->next = NULL;
        delete cursor;
        cursor = postcursor;
    }
    cout << "**  END  * cleanup **\n" << endl;
    #else
    while (cursor != NULL)
    {
        postcursor = cursor->next;
        cursor->next = NULL;
        delete cursor;
        cursor = postcursor;
    }
    #endif
}
