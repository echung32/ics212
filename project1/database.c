/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 17, 2023
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
#include <stdlib.h>
#include <string.h>
#include "record.h"

extern int debugmode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   This function adds a record into the database.
//
//  Parameters:    start (record**) : The pointer to the starting record pointer.
//                 accountnum (int) : The account number to add.
//                 name (char[]) : The account name to add.
//                 address (char[]) : The account address to add.
//
//  Return values:  void
//
 ****************************************************************/

void addRecord(struct record ** start, int accountnum, char name[], char address[])
{
    struct record * newAccount = malloc(sizeof(struct record));

    if (debugmode == 1)
    {
        printf("** START * addRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("*       name: %s\n", name);
        printf("*    address: %s\n", address);
        printf("**  END  * addRecord **\n");
    }

    newAccount->accountno = accountnum;
    strncpy(newAccount->name, name, 30);
    strncpy(newAccount->address, address, 50);
    newAccount->next = NULL;

    if (*start == NULL)
    {
        /** Add record at empty head */

        *start = newAccount;
    }
    else if (*start != NULL && accountnum < (*start)->accountno)
    {
        /** Add record at head with at least one item. */

        struct record * temp = NULL;
        temp = *start;
        *start = newAccount;
        (*start)->next = temp;
    }
    else
    {
        /** Add record somewhere else with at least one item. */

        struct record * cursor = (*start)->next;
        struct record * precursor = *start;

        while ( cursor != NULL && accountnum > cursor->accountno)
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
//  Function name: printAllRecords
//
//  DESCRIPTION:   This function prints all records stored on the
//                 database.
//
//  Parameters:    start (record*) : The starting record pointer.
//
//  Return values:  void
//
 ****************************************************************/

void printAllRecords(struct record * start)
{
    struct record * cursor = start;

    if (debugmode == 1)
    {
        printf("** START * printAllRecords **\n");
        printf("**  END  * printAllRecords **\n");
    }
    
    while (cursor != NULL)
    {
        printf("#  Account: %d\n", cursor->accountno);
        printf("#>    Name: %s\n", cursor->name);
        printf("#> Address: %s\n", cursor->address);
        cursor = cursor->next;
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   This function finds a record from the database,
//                 given an account number.
//
//  Parameters:    start (record*) : The starting record pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//                  1 : error
//
 ****************************************************************/

int findRecord(struct record * start, int accountnum)
{
    struct record * cursor = start;
    int success = 1;

    if (debugmode == 1)
    {
        printf("** START * findRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("**  END  * findRecord **\n");
    }

    while (cursor != NULL)
    {
        if (accountnum == cursor->accountno)
        {
            printf("#  Account: %d\n", cursor->accountno);
            printf("#>    Name: %s\n", cursor->name);
            printf("#> Address: %s\n", cursor->address);
            success = 0;
        }
        cursor = cursor->next;
    }

    return success;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   This function deletes a record from the database,
//                 given an account number.
//
//  Parameters:    start (record**) : The pointer to the starting pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//                  1 : error
//
 ****************************************************************/

int deleteRecord(struct record ** start, int accountnum)
{
    struct record * cursor = *start;
    struct record * precursor;
    struct record * postcursor;
    int deleted = 1;

    if (debugmode == 1)
    {
        printf("** START * deleteRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("**  END  * deleteRecord **\n");
    }
    
    while (cursor != NULL)
    {
        if (accountnum == cursor->accountno)
        {
            deleted = 0;
            if (cursor == *start)
            {
                *start = cursor->next;
                cursor->next = NULL;
                free(cursor);
                cursor = *start;
            }
            else
            {
                postcursor = cursor->next;
                cursor->next = NULL;
                free(cursor);
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
//                 It must save the records into a file.
//
//  Parameters:    start (record**) : The pointer to the starting pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//                  1 : error
//
 ****************************************************************/

int writefile(struct record * start, char filename[])
{
    FILE * ofile;
    int success = 1;
    
    if (debugmode == 1)
    {
        printf("** START * writefile **\n");
        printf("* filename: %s\n", filename);
        printf("**  END  * writefile **\n");
    }

    ofile = fopen(filename, "w");
    if (ofile != NULL)
    {
        struct record * cursor = start;
    
        while (cursor != NULL)
        {
            fprintf(ofile, "%d\n", cursor->accountno);
            fprintf(ofile, "%s\n", cursor->name);
            fprintf(ofile, "%s", cursor->address);
            
            cursor = cursor->next;
        }

        fclose(ofile);
        success = 0;
    }

    return success;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   called once before the program starts interacting with the user.
//                 It must retrieve the records from the saved file.
//
//  Parameters:    start (record**) : The pointer to the starting pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//                  1 : error
//
 ****************************************************************/
int readfile(struct record ** start, char filename[])
{
    FILE * ofile;
    int success = -1;
    
    if (debugmode == 1)
    {
        printf("** START * readfile **\n");
        printf("* filename: %s\n", filename);
        printf("**  END  * readfile **\n");
    }

    ofile = fopen(filename, "r");
    if (ofile != NULL)
    {
        int scanned = 0;
        struct record * cursor = malloc(sizeof(struct record));

        while (scanned != EOF)
        {
            int accountno;
            char name;
            char address;
            scanned = fscanf(ofile, "%d\n%30s\n%50[^\n]c", &accountno, &name, &address);
            addRecord(start, accountno, &name, &address);
        }

        fclose(ofile);
        free(cursor);
        success = 0;
    }

    return success;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   called at the end. It must release all the allocated
//                 spaces in the heap memory and assign NULL to start.
//
//  Parameters:    start (record**) : The pointer to the starting pointer
//
//  Return values:  0 : success
//
 ****************************************************************/
void cleanup(struct record ** start)
{
    if (debugmode == 1)
    {
        printf("** START * cleanup **\n");
        printf("* accountnum: \n");
        printf("**  END  * cleanup **\n");
    }
    
    
}