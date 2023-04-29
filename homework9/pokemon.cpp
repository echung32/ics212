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
//   This file contains the implementation for the main Pokemon
//   class, specified by the pokemon.h file, which all pokemons
//   should inherit from.
//
 ****************************************************************/

#include "pokemon.h"
#include <iostream>
using namespace std;

/*****************************************************************
//
//  Function name: Pokemon
//
//  DESCRIPTION:   This function is the constructor for the Pokemon
//                 class. It outputs that it was called.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Pokemon::Pokemon()
{
    cout << "Pokemon Constructor" << endl;
}

/*****************************************************************
//
//  Function name: ~Pokemon
//
//  DESCRIPTION:   This function is the destructor for the Pokemon
//                 class. It outputs that it was called.
//
//  Parameters:    void
//
//  Return values:  void
//
 ****************************************************************/

Pokemon::~Pokemon()
{
    cout << "Pokemon Destructor" << endl;
}
