/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 22, 2023
//
//  FILE:        template.c
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "pokemon.h"
#include "iofunctions.h"

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
    struct pokemon pokemonbank[5];
    int numpokemons;
    char name[] = "Pikachu";
    char filename[] = "hello.txt";
    int genamount;

    int index = 0;
    struct pokemon pokemonbank_2[5];
    int numpokemons_2;

    /** to initialize random number generator */
    srand(time(NULL));
    /** to bring it down to 1 digit, then bring it between 0-5 */
    genamount = (rand() % 10) % 6;

    printf("** TEST: writefile **\n");
    printf("* filename: %s\n", filename);
    printf("* genamount: %d\n", genamount);
    while (numpokemons < genamount)
    {
        pokemonbank[numpokemons].level = rand() % 100;
        strncpy(pokemonbank[numpokemons].name, name, 30);
        printf("* CREATE POKEMON (%d/%d):\n", numpokemons + 1, genamount);
        printf("* || level: %d\n", pokemonbank[numpokemons].level);
        printf("* || name: %s\n", pokemonbank[numpokemons].name);
        numpokemons++;
    }
    writefile(pokemonbank, numpokemons, filename);
    printf("** TEST: writefile **\n\n");

    printf("** TEST: readfile **\n");
    printf("* filename: %s\n", filename);

    readfile(pokemonbank_2, &numpokemons_2, filename);
    printf("* numpokemons_2: %d\n", numpokemons_2);

    while (index < numpokemons_2)
    {
        char matchtest[] = "true";
        int matching = strcmp(pokemonbank[index].name, pokemonbank_2[index].name) == 0;
        matching = matching && pokemonbank[index].level == pokemonbank_2[index].level;
        if (matching == 0)
        {
            sprintf(matchtest, "%s", "false");
        }

        printf("* READ POKEMON (%d/%d):\n", index + 1, numpokemons_2);
        printf("* || level: %d\n", pokemonbank_2[index].level);
        printf("* || name: %s\n", pokemonbank_2[index].name);
        printf("* || MATCHING: %s\n", matchtest);
        index++;
    }
    printf("** TEST: readfile **\n");

    return 1;
}
