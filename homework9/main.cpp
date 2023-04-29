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
//   Describe the file
//
****************************************************************/

#include "pokemon.h"
#include "psyduck.h"
#include "weedle.h"
#include "raichu.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void checkPokedex(Pokemon*);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
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
}

void checkPokedex(Pokemon* pokemon)
{
    pokemon->printData();
}
