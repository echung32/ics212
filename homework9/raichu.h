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
//  FILE:        raichu.h
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#ifndef RAICHU_H
#define RAICHU_H

#include "pokemon.h"

class Raichu : public Pokemon
{
    public:
        Raichu();
        ~Raichu();
        void printData();
};
#endif