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
//  FILE:        main.cpp
//
//  DESCRIPTION:
//   This program implements a simple program which uses a class hierarchy,
//   by creating a Pokedex example where 3 pokemons are added to the "Pokedex",
//   which are contaiend in a Map, accessed through a Vector containing the
//   nicknames to these pokemons. Then, it calls the Pokemon's "printData()"
//   function to show the details held within those Pokemons. This program also
//   demonstrates the usage of virtual functions.
//
 ****************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "pokemon.h"
#include "psyduck.h"
#include "weedle.h"
#include "raichu.h"

using namespace std;

void checkPokedex(Pokemon*);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This function is the driver code to test the
//                 constructors and destructors of the Pokemon
//                 classes, and uses Vectors and Maps to store and
//                 show a Pokemon's details.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//
 ****************************************************************/

int main(int argc, char* argv[])
{
    cout << "~~ Call constructors ~~" << endl;
    Pokemon * psyduck = new Psyduck();
    Pokemon * weedle = new Weedle();
    Pokemon * raichu = new Raichu();

    vector<string> pokeVector;
    vector<string>::iterator pokeIterator;
    map<string, Pokemon*> pokeMap;

    cout << "\n~~ Assign nicknames to pokeVector ~~" << endl;

    cout << "~ Psyduck as John" << endl;
    pokeVector.push_back("John");

    cout << "~ Weedle as Nick" << endl;
    pokeVector.push_back("Nick");

    cout << "~ Raichu as Paul" << endl;
    pokeVector.push_back("Paul");

    cout << "\n~~ Assign key and pokemon to pokeMap ~~" << endl;

    cout << "~ pokeMap[" << pokeVector.at(0) << "] = Psyduck" << endl;
    pokeMap[pokeVector.at(0)] = psyduck;

    cout << "~ pokeMap[" << pokeVector.at(1) << "] = Weedle" << endl;
    pokeMap[pokeVector.at(1)] = weedle;

    cout << "~ pokeMap[" << pokeVector.at(2) << "] = Raichu" << endl;
    pokeMap[pokeVector.at(2)] = raichu;

    cout << "\n~~ Access checkPokedex using pokeIterator ~~" << endl;

    for (pokeIterator = pokeVector.begin(); pokeIterator != pokeVector.end(); pokeIterator++)
    {
        cout << "~ pokeMap[" << *pokeIterator << "]" << endl;
        checkPokedex(pokeMap[*pokeIterator]);
    }

    cout << "\n~~ Call destructors ~~" << endl;
    delete psyduck;
    delete weedle;
    delete raichu;

    return 0;
}

/*****************************************************************
//
//  Function name: checkPokedex
//
//  DESCRIPTION:   This function calls the "printData()" function
//                 of the pokemon given.
//
//  Parameters:    pokemon (Pokemon*) : A pointer to the pokemon object.
//
//  Return values:  void
//
 ****************************************************************/

void checkPokedex(Pokemon* pokemon)
{
    pokemon->printData();
}
