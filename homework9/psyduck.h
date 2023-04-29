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
//   Describe the file
//
****************************************************************/

#ifndef PSYDUCK_H
#define PSYDUCK_H

#include <string>
#include "pokemon.h"

class Psyduck : public Pokemon
{
    public:
        Psyduck();
        ~Psyduck();
        void printData();
};
#endif