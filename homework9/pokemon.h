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
//  FILE:        pokemon.h
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
    protected:
        std::string type;
        float weight;

    public:
        Pokemon();
        virtual ~Pokemon();
        virtual void printData() = 0;
};
#endif