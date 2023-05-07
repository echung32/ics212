/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        May 6, 2023
//
//  FILE:        homework10.java
//
//  DESCRIPTION:
//   This is the frontend user interface component of the
//   number multiple of 5 checker. This accepts user input
//   and prints the output to the terminal. Backend code is
//   written in C and is used by this class.
//
****************************************************************/

import java.util.Scanner;

public class homework10
{
    static
    {
       System.loadLibrary("homework10");
    }
  
    private static native int is_multiple5(int number);

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

    public static void main(String[] args)
    {
        homework10 ui = new homework10();
        ui.print_table(ui.user_interface());  
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

    public int user_interface()
    {
        Scanner scan = new Scanner(System.in);
        int number = 0;
        boolean success = false;

        System.out.printf("This program checks which numbers, in the sequence from 0 to a number");
        System.out.printf(", are multiples of 5.\n\n");
        while (success == false)
        {
            System.out.printf("Enter maximum number to show: ");

            if (scan.hasNextInt())
            {
                number = scan.nextInt();
                if (number == 0)
                {
                    System.out.println("You must enter a positive integer greater than 0. Try again!");
                }
                else
                {
                    success = true;
                }
            }
            else
            {
                System.out.println("You must enter a valid integer. Try again!");
                scan.nextLine();
            }
        }

        scan.close();
        return number;
    }

    /*****************************************************************
    //
    //  Function name: print_table
    //
    //  DESCRIPTION:   Print the numbers from 0..number and check
    //                 which numbers are multiple of 5 from that
    //                 sequence. This calls a function, is_multiple5,
    //                 which is implemented in C code.
    //
    //  Parameters:    number (int) : The number to check multiples up to
    //
    //  Return values:  void : directly prints to stdout
    //
    ****************************************************************/

    public void print_table(int number)
    {
        int index;
        System.out.printf("  Number");
        System.out.printf("  Multiple of 5?\n");
    
        for (index = 0; index <= number; index++)
        {
            int isMultiple = is_multiple5(index);
            String result = "No";
            if (isMultiple == 1)
            {
                result = "Yes";
            }
            System.out.printf("  %6d  %3s\n", index, result);
        }
    } 
 }
