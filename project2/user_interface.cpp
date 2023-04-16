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
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:
//   This is the user interface component to the
//   bank database application, which handles data
//   entry and parsing of that data to be added
//   into the database.
//
 ****************************************************************/

#include <iostream>
#include <string.h>
#include "llist.h"

void getaddress(char address[], int length);
void getAccountNum(int &accountnum);

using namespace std;

int debugmode = 0;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This is the entrypoint to the user interface,
//                 which handles validation of user input and has
//                 auto-complete for command options. For debugging,
//                 the user can pass in the "debug" parameter to
//                 see what is being done in the database.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  1 : success
//
 ****************************************************************/
int main(int argc, char* argv[])
{
    char filename[] = "database.txt";
    llist *start = new llist(filename);
    int quit = 0;

    #ifdef debug
        debugmode = 1;
    #endif

    if (debugmode == 1)
    {
        cout << "** DEBUG RELEASE **\n" << endl;
    }

    cout << "Welcome, banker!" << flush;
    cout << " This program allows you to easily find" << flush;
    cout << " and manage customer bank records stored on the database.\n" << endl;

    while (quit == 0)
    {
        char option[100];

        cout << ">> What do you want to do?" << endl;
        cout << "- add: add a new record in the database" << endl;
        cout << "- printall: print all records in the database" << endl;
        cout << "- find: find record(s) with a specified account #" << endl;
        cout << "- delete: delete existing record(s) from the" << flush;
        cout << " database using the account # as a key" << endl;
        cout << "- quit: quit the program" << endl;
        cout << "> " << flush;

        cin.getline(option, 100);

        if (strlen(option) != 0 && strncmp(option, "add", strlen(option)) == 0)
        {
            struct record data = {0};
            int successful = 0;

            cout << "\n>> You are adding a new account." << endl;

            /** Account number */
            getAccountNum(data.accountno);

            /** Name */
            do
            {
                cout << "> Enter customer name below." << endl;
                cout << "- Maximum of 30 characters. You can input more, but it will be ignored." << endl;
                cout << "> " << flush;

                cin.getline(data.name, 30);

                if (strlen(data.name) == 0)
                {
                    cout << "!! You must input at least one character. Please try again.\n" << endl;
                }
                else
                {
                    successful = 1;
                }
            }
            while (successful == 0);

            /** Address */
            cout << "> Enter customer address below." << endl;
            cout << "- Maximum of 50 characters. You can input more, but it will be ignored." << endl;
            cout << "- Stop input by pressing '~ -> ENTER'." << endl;
            getaddress(data.address, 50);

            /** Add to database */
            start->addRecord(data.accountno, data.name, data.address);
            cout << ">> You've added a new account.\n\n" << endl;
        }
        else if (strlen(option) != 0 && strncmp(option, "printall", strlen(option)) == 0)
        {
            cout << ">> You are printing all accounts." << endl;
            start->printAllRecords();
            cout << ">> All records have been printed.\n" << endl;
        }
        else if (strlen(option) != 0 && strncmp(option, "find", strlen(option)) == 0)
        {
            int accountno = 0;

            cout << ">> You are finding an account.\n" << endl;
            /** Account number */
            getAccountNum(accountno);

            /** Find record in database */
            if (start->findRecord(accountno) == 0)
            {
                cout << ">> You've found an account.\n" << endl;
            }
            else
            {
                cout << ">> Account " << accountno <<" could not be found.\n" << endl;
            }
        }
        else if (strlen(option) != 0 && strncmp(option, "delete", strlen(option)) == 0)
        {
            int accountno = 0;

            cout << ">> You are deleting an account." << endl;
            /** Account number */
            getAccountNum(accountno);

            /** Delete record in database */
            if (start->deleteRecord(accountno) == 0)
            {
                cout << ">> You have deleted an account.\n" << endl;
            }
            else
            {
                cout << ">> Account " << accountno << " could not be found.\n" << endl;
            }
        }
        else if (strlen(option) != 0 && strncmp(option, "quit", strlen(option)) == 0)
        {
            cout << ">> Goodbye, banker!" << endl;
            quit = 1;
        }
        else
        {
            cout << "!! Invalid option. Please try again!\n" << endl;
        }
    }

    return 1;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   This helper function accepts a multi-line
//                 input from the user and stores the value
//                 into the address pointer. The primary purpose
//                 is to accept the inputted address.
//
//  Parameters:    address (char[]) : A pointer to store the customer's address.
//                 length (int) : The maximum length of the address.
//
//  Return values:  void
//
 ****************************************************************/

void getaddress(char address[], int length)
{
    if (debugmode == 1)
    {
        cout << "** START * getaddress **" << endl;
        cout << "* address: " << address << endl;
        cout << "*  length: " << length << endl;
        cout << "**  END  * getaddress **" << endl;
    }

    cin.getline(address, length, '~');
    cin.ignore(1000, '\n');
}

/*****************************************************************
//
//  Function name: getAccountNum
//
//  DESCRIPTION:   This helper
//
//  Parameters:    address (char[]) : A pointer to store the customer's address.
//                 length (int) : The maximum length of the address.
//
//  Return values:  void
//
 ****************************************************************/

void getAccountNum(int &accountnum)
{
    int successful = 0;

    do
    {
        /**
         * Max 8 characters to prevent integer overflow issues.
         */

        cout << "> Enter account number below." << endl;
        cout << "- Maximum of 8 characters. You can input more, but it will be ignored." << endl;
        cout << "> " << flush;

        if (!(cin >> accountnum))
        {
            cout << "!! Account numbers must be integers >= 0. Please try again.\n\n" << endl;
            cin.ignore(1000, '\n');
        }
        else
        {
            cin.ignore(1000, '\n');
            successful = 1;
        }
    }
    while (successful == 0);

    if (debugmode == 1)
    {
        cout << "** START * getAccountNum **" << endl;
        cout << "* accountnum: " << accountnum << endl;
        cout << "**  END  * getAccountNum **" << endl;
    }
}
