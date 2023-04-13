/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 6, 2023
//
//  FILE:        database.c
//
//  DESCRIPTION:
//   This is the database component to the bank database
//   application, which handles the methods used to
//   add, print, find, and delete records within the
//   database.
//
 ****************************************************************/

#include <stdio.h>
#include "record.h"

extern int debugmode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   This function adds a record into the database.
//
//  Parameters:    data (record**) : The pointer to the starting record pointer.
//                 accountnum (int) : The account number to add.
//                 name (char[]) : The account name to add.
//                 address (char[]) : The account address to add.
//
//  Return values:  void
//
 ****************************************************************/

void addRecord(struct record ** data, int accountnum, char name[], char address[])
{
    if (debugmode == 1)
    {
        printf("** START * addRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("*       name: %s\n", name);
        printf("*    address: %s\n", address);
        printf("**  END  * addRecord **\n");
    }
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   This function prints all records stored on the
//                 database.
//
//  Parameters:    data (record*) : The starting record pointer.
//
//  Return values:  void
//
 ****************************************************************/

void printAllRecords(struct record * data)
{
    if (debugmode == 1)
    {
        printf("** START * printAllRecords **\n");
        printf("**  END  * printAllRecords **\n");
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   This function finds a record from the database,
//                 given an account number.
//
//  Parameters:    data (record*) : The starting record pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//
 ****************************************************************/

int findRecord(struct record * data, int accountnum)
{
    if (debugmode == 1)
    {
        printf("** START * findRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("**  END  * findRecord **\n");
    }
    return 0;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   This function deletes a record from the database,
//                 given an account number.
//
//  Parameters:    data (record**) : The pointer to the starting pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//
 ****************************************************************/

int deleteRecord(struct record ** data, int accountnum)
{
    if (debugmode == 1)
    {
        printf("** START * deleteRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("**  END  * deleteRecord **\n");
    }
    return 0;
}
