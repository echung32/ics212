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
//   This file contains the class and function prototypes for the main
//   Pokemon class, which all pokemons should be subclasses of.
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
