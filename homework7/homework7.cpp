/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 31, 2023
//
//  FILE:        homework7.cpp
//
//  DESCRIPTION:
//   A program that accepts a numerical input from the user
//   and prints whether every number up to the input inclusive
//   is a multiple of 5.
//
 ****************************************************************/

#include <iostream>
#include <iomanip>

int user_interface();
void is_multiple5(int number, int &isMultiple);
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
    int number;
    int successful = 0;

    std::cout << "This program checks which numbers, in the sequence from 0 to a number" << std::flush;
    std::cout << ", are multiples of 5.\n" << std::endl;

    do
    {
        std::cout << "Enter maximum number to show: " << std::flush;
        std::cin >> number;

        if (number <= 0)
        {
            std::cout << "You must enter a positive integer greater than 0. Try again!\n" << std::endl;
        }
        else if (!std::cin.good())  
        {
            std::cout << "You must enter a valid integer. Try again!\n" << std::endl;
        }
        else
        {
            successful = 1;
        }
        
        std::cin.clear();
        std::cin.ignore(100, '\n');
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
//                 isMultiple (int&) : Result of the check.
//                            1 for multiple, 0 for not multiple.
//
//  Return values:  void : result is in isMultiple variable.
//
 ****************************************************************/

void is_multiple5(int number, int &isMultiple)
{
    if ( number % 5 == 0 )
    {
        isMultiple = 1;
    }
    else
    {
        isMultiple = 0;
    }
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
    int isMultiple;

    std::cout << "  Number" << std::flush;
    std::cout << "  Multiple of 5?" << std::endl;

    for ( index = 0; index <= number; index++ )
    {
        is_multiple5(index, isMultiple);
        std::cout << std::setw(8) << index << std::setw(5) << std::flush;
        
        if (isMultiple == 1)
        {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
