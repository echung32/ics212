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
//   Describe the file
//
****************************************************************/

#include "psyduck.h"
#include <iostream>
using namespace std;

/*****************************************************************
//
//  Function name: foo
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

Psyduck::Psyduck()
{
    this->type = "water";
    this->weight = 43.2;
}

Psyduck::~Psyduck()
{
    cout << "called psyduck destructor" << endl;
}

void Psyduck::printData()
{
    cout << "Name: " << "Psyduck" << endl;
    cout << "Type: " << this->type << endl;
    cout << "Weight: " << this->weight << endl;
}
