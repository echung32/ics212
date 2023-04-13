/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        January 16, 2023
//
//  FILE:        homework2.c
//
//  DESCRIPTION:
//   A program that accepts a numerical input from the user
//   and prints whether every number up to the input inclusive
//   is a multiple of 5.
//
 ****************************************************************/

#include <stdio.h>
int user_interface();
int is_multiple5(int number);
void print_table(int number);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION: Calls the user_interface method to ask the user
//               for a valid number, then calls print_table() to
//               list, from 0..number the numbers that are
//               multiples of 5 and the numbers that aren't. 
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
    int number;
    number = user_interface();
    print_table(number);
    return 1;
}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Prompts the user to enter a number, and validates
//                 that the inputted value is actually a number that
//                 is greater than 0, and is not a word. If the input
//                 is invalid, then it will re-prompt the user to
//                 input a new number.
//
//  Parameters:    N/A
//
//  Return values:  0..x : A positive integer inputted by the user
//
 ****************************************************************/

int user_interface()
{
    char buffer[100];
    int numberFromBuffer;
    int number;
    int successful = 0;

    printf("This program checks which numbers, in the sequence from 0 to a number");
    printf(", are multiples of 5.\n\n");

    do
    {
        printf("Enter maximum number to show: ");
        /** Ask user input, up to 99 chars */
        scanf("%99s", buffer);
        /** Look for a digit in the buffer, then set it to number. */
        numberFromBuffer = sscanf(buffer, "%d", &number);

        if (numberFromBuffer == 1 && number <= 0)
        {
            printf("You must enter a positive integer greater than 0. Try again!\n");
        }
        else if (numberFromBuffer != 1)
        {
            printf("You must enter a valid integer. Try again!\n");
        }
        else
        {
            successful = 1;
        }
    }
    while (successful == 0);

    return number;
}

/*****************************************************************
//
//  Function name: is_multiple5
//
//  DESCRIPTION:   Check whether the inputted value is a multiple
//                 of 5 or not.
//
//  Parameters:    number (int) : The number to check
//
//  Return values:  1 : multiple of 5
//                  0 : not a multiple of 5
//
 ****************************************************************/

int is_multiple5(int number)
{
    int returnValue = 0;
    if ( number % 5 == 0 )
    {
        returnValue = 1;
    }

    return returnValue;
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   Print the numbers from 0..number and check
//                 which numbers are multiple of 5 from that
//                 sequence.
//
//  Parameters:    number (int) : The number to check multiples up to
//
//  Return values:  void : directly prints to stdout
//
 ****************************************************************/

void print_table(int number)
{
    int index;
    printf("  Number");
    printf("  Multiple of 5?\n");

    for ( index = 0; index <= number; index++ )
    {
        int isMultiple = is_multiple5(index);
        char* result = "No";
        if (isMultiple == 1)
        {
            result = "Yes";
        }
        printf("  %6d  %3s\n", index, result);
    }
}
