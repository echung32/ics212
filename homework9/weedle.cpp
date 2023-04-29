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
//  FILE:        weedle.cpp
//
//  DESCRIPTION:
//   This file contains the implementation for the Weedle class,
//   specified by the weedle.h file, which is a subclass of the
//   Pokemon class. This file implements the data of Weedle,
//   including its type, weight, and adds a function to print this
//   information to the terminal.
//
 ****************************************************************/

#include <iostream>

#include "weedle.h"

using namespace std;

/*****************************************************************
//
//  Function name: Weedle
//
//  DESCRIPTION:   This function is the constructor for the Weedle
//                 class. It outputs that it was called, and assigns
//                 the type and weight variables.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Weedle::Weedle()
{
    cout << "Weedle Constructor" << endl;

    this->type = "bug, poison";
    this->weight = 7.1;
}

/*****************************************************************
//
//  Function name: ~Weedle
//
//  DESCRIPTION:   This function is the destructor for the Weedle
//                 class. It outputs that it was called.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Weedle::~Weedle()
{
    cout << "Weedle Destructor" << endl;
}

/*****************************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   This function prints the name, type, and weight
//                 of the Pokemon.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

void Weedle::printData()
{
    cout << "Name: " << "Weedle" << endl;
    cout << "Type: " << this->type << endl;
    cout << "Weight: " << this->weight << endl;
}
