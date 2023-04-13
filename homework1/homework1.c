/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        January 16, 2023
//
//  FILE:        homework1.c
//
//  DESCRIPTION:
//   A copy of the helloworld.java file, written in C.
//
****************************************************************/

#include <stdio.h>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Prints Hello World and where the while loops
//                 and do-while loops executed. 
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
    int num;
    int i;

    for (i = 0; i < 6; i = i + 1)
    {
        if (i < 2) {
            printf("Hello\n");
        } else if ( i < 4 ) {
            printf("World\n");
        } else {
            printf("!!!\n");
        }
    }

    num = 0;
    while (num < 3)
    {
        printf("While loop!\n");
        num = num + 1;
    }

    num = 0;
    do
    {
        printf("Do-while loop!\n");
        num = num + 1;
    }
    while (num < 3);     

    return 0;

}
