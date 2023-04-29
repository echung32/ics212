/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 28, 2023
//
//  FILE:        main.cpp
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#include "pokemon.h"
#include "psyduck.h"
#include "weedle.h"
#include "raichu.h"
#include <iostream>
using namespace std;

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

int main(int argc, char* argv[])
{
    Pokemon * psyduck = new Psyduck();
    Pokemon * weedle = new Weedle();
    Pokemon * raichu = new Raichu();

    psyduck->printData();
    weedle->printData();
    raichu->printData();

    delete psyduck;
    delete weedle;
    delete raichu;
}
