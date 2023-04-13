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
    struct record * temp = malloc(sizeof(struct record));
    struct record * cursor = NULL;

    if (debugmode == 1)
    {
        printf("** START * addRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("*       name: %s\n", name);
        printf("*    address: %s\n", address);
        printf("**  END  * addRecord **\n");
    }

    temp[0].accountno = accountnum;
    strncpy(name, temp[0].name, 30);
    strncpy(address, temp[0].address, 50);
    temp[0].next = NULL;
    
    /** Add record at head */
    if (start == NULL || accountnum < (*start)->accountno)
    {
        cursor = *start;
        *start = temp;
        (*start)->next = cursor;
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
//  Parameters:    start (record*) : The starting record pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//
 ****************************************************************/

int findRecord(struct record * start, int accountnum)
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
//  Parameters:    start (record**) : The pointer to the starting pointer
//                 accountnum (int) : The account number to delete
//
//  Return values:  0 : success
//
 ****************************************************************/

int deleteRecord(struct record ** start, int accountnum)
{
    if (debugmode == 1)
    {
        printf("** START * deleteRecord **\n");
        printf("* accountnum: %d\n", accountnum);
        printf("**  END  * deleteRecord **\n");
    }
    return 0;
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
//
 ****************************************************************/

int writefile(struct record * start, char filename[])
{
    FILE * ofile;
    int success = -1;
    
    if (debugmode == 1)
    {
        printf("** START * writefile **\n");
        printf("* filename: %s\n", filename);
        printf("**  END  * writefile **\n");
    }

    ofile = fopen(filename, "w");
    if (ofile != NULL)
    {
        /**
         * int index = 0;
         * while ( index < num )
         * {
         *     char level[20];
         *     sprintf(level, "%d", pokearray[index].level);
         * 
         *     fputs(level, ofile);
         *     fputs("\n", ofile);
         *     fputs(pokearray[index].name, ofile);
         *     fputs("\n", ofile);
         * 
         *     index++;
         * }
         */
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
        /**
         * 
         * int index = 0;
         * int scanned = 0;
         * 
         * while ( index < *num && scanned != EOF )
         * {
         *     scanned = fscanf(ofile, "%d\n%s", &pokearray[index].level, pokearray[index].name);
         * 
         *     if (scanned != EOF)
         *     {
         *         index++;
         *     }
         * }
         * 
         * *num = index;
         */ 
        fclose(ofile);
        fflush(ofile);
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