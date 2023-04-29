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
//   Describe the file
//
****************************************************************/

#include "weedle.h"
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

Weedle::Weedle()
{
    cout << "called weedle constructor" << endl;

    this->type = "bug, poison";
    this->weight = 7.1;
}

Weedle::~Weedle()
{
    cout << "called weedle destructor" << endl;
}

void Weedle::printData()
{
    cout << "Name: " << "Weedle" << endl;
    cout << "Type: " << this->type << endl;
    cout << "Weight: " << this->weight << endl;
}
