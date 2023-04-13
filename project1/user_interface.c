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
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   This is the user interface component to the
//   bank database application, which handles data
//   entry and parsing of that data to be added
//   into the database.
//
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include "record.h"
#include "database.h"

void getaddress(char address[], int length);
void getAccountNum(int *accountnum);

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
    struct record * start = NULL;
    char filename[] = "database.txt";
    int quit = 0;

    /** Handle Debug Mode */
    if (argc > 1)
    {
        /** Handle when more than 2 arguments */
        if (argc > 2)
        {
            quit = 1;
        }
        /** Handle exact "debug" match */
        else if (strlen(argv[1]) == 5 && strncmp(argv[1], "debug", 5) == 0)
        {
            printf("** DEBUG MODE ENABLED **\n");
            debugmode = 1;
        }
        /** Handle when 2nd argument is invalid */
        else
        {
            quit = 1;
        }

        /** Handle error message */
        if (quit == 1)
        {
            printf("** ERROR: Invalid arguments!\n");
        }
    }

    if (quit == 0)
    {
        printf("Welcome, banker!");
        printf(" This program allows you to easily find");
        printf(" and manage customer bank records stored on the database.\n\n");
        readfile(&start, filename);
    }
    while (quit == 0)
    {
        char option[100];

        printf(">> What do you want to do?\n");
        printf("- add: add a new record in the database\n");
        printf("- printall: print all records in the database\n");
        printf("- find: find record(s) with a specified account #\n");
        printf("- delete: delete existing record(s) from the");
        printf(" database using the account # as a key\n");
        printf("- quit: quit the program\n");
        printf("> ");

        fgets(option, 100, stdin);
        option[strcspn(option, "\n")] = 0;

        if (strlen(option) != 0 && strncmp(option, "add", strlen(option)) == 0)
        {
            struct record data = {0};
            int successful = 0;

            printf("\n>> You are adding a new account.\n");

            /** Account number */
            getAccountNum(&data.accountno);

            /** Name */
            do
            {
                int index = 0;
                int character; /** Holds current getchar'd character */

                printf("> Enter customer name below.\n");
                printf("- Maximum of 30 characters. You can input more, but it will be ignored.\n");
                printf("> ");

                /**
                 * Keep track of an index in order to add into the name properly,
                 * and to ensure the size is length - 1 (for last '/0' character).
                 */

                while ((character = fgetc(stdin)) != '\n')
                {
                    /** Continue to eat up the characters from stdin, but don't add. */

                    if (index < 29)
                    {
                        data.name[index] = character;
                        index = index + 1;
                    }
                }

                /** Remove newline from fgetc result */
                data.name[strcspn(data.name, "\n")] = 0;

                if (strlen(data.name) == 0)
                {
                    printf("!! You must input at least one character. Please try again.\n\n");
                }
                else
                {
                    successful = 1;
                }
            }
            while (successful == 0);

            /** Address */
            printf("> Enter customer address below.\n");
            printf("- Maximum of 50 characters. You can input more, but it will be ignored.\n");
            printf("- Stop input by pressing 'ENTER -> CTRL+D'.\n");
            getaddress(data.address, 50);

            /** Add to database */
            addRecord(&start, data.accountno, data.name, data.address);
            printf(">> You've added a new account.\n\n");
        }
        else if (strlen(option) != 0 && strncmp(option, "printall", strlen(option)) == 0)
        {
            printf(">> You are printing all accounts.\n");
            printAllRecords(start);
            printf(">> All records have been printed.\n\n");
        }
        else if (strlen(option) != 0 && strncmp(option, "find", strlen(option)) == 0)
        {
            int accountno = 0;

            printf(">> You are finding an account.\n");
            /** Account number */
            getAccountNum(&accountno);

            /** Find record in database */
            if (findRecord(start, accountno) == 0)
            {
                printf(">> You've found an account.\n\n");
            }
            else
            {
                printf(">> Account %d could not be found.\n\n", accountno);
            }
        }
        else if (strlen(option) != 0 && strncmp(option, "delete", strlen(option)) == 0)
        {
            int accountno = 0;

            printf(">> You are deleting an account.\n");
            /** Account number */
            getAccountNum(&accountno);

            /** Delete record in database */
            
            if (deleteRecord(&start, accountno) == 0)
            {
                printf(">> You have deleted an account.\n\n");
            }
            else
            {
                printf(">> Account %d could not be found.\n\n", accountno);
            }
        }
        else if (strlen(option) != 0 && strncmp(option, "quit", strlen(option)) == 0)
        {
            printf(">> Goodbye, banker!\n");
            writefile(start, filename);
            cleanup(&start);
            quit = 1;
        }
        else
        {
            printf("!! Invalid option. Please try again!\n\n");
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
    int index = 0;
    int character; /** Holds current getchar'd character */

    if (debugmode == 1)
    {
        printf("** START * getaddress **\n");
        printf("* address: %s\n", address);
        printf("*  length: %d\n", length);
        printf("**  END  * getaddress **\n");
    }

    /**
     * Keep track of an index in order to add into the address properly,
     * and to ensure the size is length - 1 (for last '/0' character).
     */

    while ((character = fgetc(stdin)) != EOF)
    {
        /** Continue to eat up the characters from stdin, but don't add. */
        if (index < length - 1)
        {
            address[index] = character;
            index = index + 1;
        }
    }
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

void getAccountNum(int *accountnum)
{
    int successful = 0;
   
    do
    {
        char buffer[9];
        int scannerresult = 0;
        int index = 0;
        int character;

        /**
         * Max 8 characters to prevent integer overflow issues.
         */

        printf("> Enter account number below.\n");
        printf("- Maximum of 8 characters. You can input more, but it will be ignored.\n");
        printf("> ");

        /**
         * Keep track of an index in order to add into the name properly,
         * and to ensure the size is length - 1 (for last '/0' character).
         */

        while ((character = fgetc(stdin)) != '\n')
        {
            /** Continue to eat up the characters from stdin, but don't add. */

            if (index < 8)
            {
                buffer[index] = character;
                index = index + 1;
            }
        }

        /** Remove newline from fgetc result */
        buffer[strcspn(buffer, "\n")] = 0;

        /** Look for a digit in the buffer, then set it to number. */
        scannerresult = sscanf(buffer, "%8d", accountnum);

        if (scannerresult != 1 || (scannerresult == 1 && *accountnum <= 0))
        {
            printf("!! Account numbers must be integers >= 0. Please try again.\n\n");
        }
        else
        {
            successful = 1;
        }
    }
    while (successful == 0);
}
