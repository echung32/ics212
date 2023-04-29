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
//  FILE:        pokemon.cpp
//
//  DESCRIPTION:
//   This file contains the implementation for the Psyduck class,
//   specified by the psyduck.h file, which is a subclass of the
//   Pokemon class. This file implements the data of Psyduck,
//   including its type, weight, and adds a function to print this
//   information to the terminal.
//
 ****************************************************************/

#include <iostream>

#include "psyduck.h"

using namespace std;

/*****************************************************************
//
//  Function name: Psyduck
//
//  DESCRIPTION:   This function is the constructor for the Psyduck
//                 class. It outputs that it was called, and assigns
//                 the type and weight variables.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Psyduck::Psyduck()
{
    cout << "Psyduck Constructor" << endl;

    this->type = "water";
    this->weight = 43.2;
}

/*****************************************************************
//
//  Function name: ~Psyduck
//
//  DESCRIPTION:   This function is the destructor for the Psyduck
//                 class. It outputs that it was called.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Psyduck::~Psyduck()
{
    cout << "Psyduck Destructor" << endl;
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

void Psyduck::printData()
{
    cout << "Name: " << "Psyduck" << endl;
    cout << "Type: " << this->type << endl;
    cout << "Weight: " << this->weight << endl;
}
