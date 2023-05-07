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
//  FILE:        homework10.c
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#include "homework10.h"

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

JNIEXPORT jint JNICALL Java_homework10_is_1multiple5(JNIEnv * env, jclass class, jint number)
{
    int returnValue = 0;
    if ( number % 5 == 0 )
    {
        returnValue = 1;
    }

    return returnValue;
}