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
//  FILE:        raichu.cpp
//
//  DESCRIPTION:
//   This file contains the implementation for the Raichu class,
//   specified by the raichu.h file, which is a subclass of the
//   Pokemon class. This file implements the data of Raichu,
//   including its type, weight, and adds a function to print this
//   information to the terminal.
//
 ****************************************************************/

#include "raichu.h"
#include <iostream>
using namespace std;

/*****************************************************************
//
//  Function name: Raichu
//
//  DESCRIPTION:   This function is the constructor for the Raichu
//                 class. It outputs that it was called, and assigns
//                 the type and weight variables.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Raichu::Raichu()
{
    cout << "Raichu Constructor" << endl;

    this->type = "electric";
    this->weight = 66.1;
}

/*****************************************************************
//
//  Function name: ~Raichu
//
//  DESCRIPTION:   This function is the destructor for the Raichu
//                 class. It outputs that it was called.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Raichu::~Raichu()
{
    cout << "Raichu Destructor" << endl;
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

void Raichu::printData()
{
    cout << "Name: " << "Raichu" << endl;
    cout << "Type: " << this->type << endl;
    cout << "Weight: " << this->weight << endl;
}
