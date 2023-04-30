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
//  FILE:        weedle.h
//
//  DESCRIPTION:
//   This file contains the class and function prototypes for the
//   Weedle class, which is a subclass of the Pokemon class.
//
 ****************************************************************/

#ifndef WEEDLE_H
#define WEEDLE_H

#include "pokemon.h"

class Weedle : public Pokemon
{
public:
    Weedle();
    ~Weedle();
    void printData();
};
#endif
