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
//   Describe the file
//
****************************************************************/

import java.util.Scanner;

public class homework10 {
    static
    {
       System.loadLibrary("homework10");
    }
  
    private static native int is_multiple5(int number);
  
    public static void main(String[] args)
    {
        homework10 ui = new homework10();
        ui.print_table(ui.user_interface());  
    }

    public int user_interface()
    {
        Scanner scan = new Scanner(System.in);
        int number = 0;
        boolean success = false;

        while (success == false)
        {
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