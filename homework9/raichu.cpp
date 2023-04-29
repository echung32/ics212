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
//   Describe the file
//
****************************************************************/

#include "raichu.h"
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

Raichu::Raichu()
{
    cout << "called raichu constructor" << endl;

    this->type = "electric";
    this->weight = 66.1;
}

Raichu::~Raichu()
{
    cout << "called weedle destructor" << endl;
}

void Raichu::printData()
{
    cout << "Name: " << "Raichu" << endl;
    cout << "Type: " << this->type << endl;
    cout << "Weight: " << this->weight << endl;
}
