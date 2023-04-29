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
//  FILE:        psyduck.h
//
//  DESCRIPTION:
//   This file contains the class and function prototypes for the
//   Psyduck class, which is a subclass of the Pokemon class.
//
 ****************************************************************/

#ifndef PSYDUCK_H
#define PSYDUCK_H

#include "pokemon.h"

class Psyduck : public Pokemon
{
    public:
        Psyduck();
        ~Psyduck();
        void printData();
};
#endif
