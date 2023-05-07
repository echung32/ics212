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
//   This is the backend component for the number multiple checker.
//   Code written in Java can call this fucntion to use the methods.
//
****************************************************************/

#include "homework10.h"

/*****************************************************************
//
//  Function name: is_multiple5
//
//  DESCRIPTION:   Check whether the inputted value is a multiple
//                 of 5 or not.
//
//  Parameters:     env (JNIEnv*) : the JNI environment pointer
//                  class (jclass) : the java class calling the function
//                  number (jint) : The number to check
//
//  Return values:  1 : multiple of 5
//                  0 : not a multiple of 5
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
