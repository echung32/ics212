/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 22, 2023
//
//  FILE:        driver.c
//
//  DESCRIPTION:
//   This driver file runs the read/write functions to test the
//   functionality of the iofunctions and makes sure they behave
//   as expected.
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
//  DESCRIPTION:   This calls the read/write functions in iofunctions.c
//                 and tests their functions by first creating a randomized
//                 test inputs, attempting to read a nonexistent file, and
//                 finally reading into a smaller pokebank.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  1 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    int othertests = 1;
    int repeats = 0;
    int repeatTimes = 5;
    char filename[] = "pokebank.txt";
    char * name[] = {"Pikachu", "Pichu", "Bulbasaur", "Charmander", "Raichu", "Squirtle", "Minun"};

    /** to initialize random number generator */
    srand(time(NULL));

    /** repeat random test 5 times */
    printf("---- START: 1-5 TESTS ----\n\n");
    while (repeats <= repeatTimes)
    {
        int randomname;
        int readwritesuccess = -1;
        
        struct pokemon pokemonbank[5];
        int numpokemons = 0;

        printf("** TEST: writefile (RUN %d/%d) **\n", repeats, repeatTimes);
        printf("* filename: %s\n", filename);
        printf("* amount: %d\n", repeats);
        while (numpokemons < repeats)
        {
            randomname = (rand() % 10) % 7;

            pokemonbank[numpokemons].level = rand() % 100;
            strncpy(pokemonbank[numpokemons].name, name[randomname], 30);
            printf("* CREATE POKEMON (%d/%d):\n", numpokemons + 1, repeats);
            printf("* || level: %d\n", pokemonbank[numpokemons].level);
            printf("* || name: %s\n", pokemonbank[numpokemons].name);
            numpokemons++;
        }

        readwritesuccess = writefile(pokemonbank, numpokemons, filename);
        if ( readwritesuccess == 0 )
        {
            printf("* SUCCESSFUL WRITE\n");
        }
        else
        {
            printf("* FAILED WRITE\n");
        }

        printf("** TEST: writefile (RUN %d/%d) **\n\n", repeats, repeatTimes);

        printf("** TEST: readfile (RUN %d/%d) **\n", repeats, repeatTimes);
        printf("* filename: %s\n", filename);

        if ( readwritesuccess == 0 )
        {
            int index = 0;
            struct pokemon pokemonbank_2[5];
            int numpokemons_2 = 5;

            readwritesuccess = readfile(pokemonbank_2, &numpokemons_2, filename);
            if ( readwritesuccess == 0 )
            {
                printf("* SUCCESSFUL READ\n");
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
            }
            else
            {
                printf("* FAILED READ\n");
            }
        }
        else
        {
            printf("* SKIPPED READ DUE TO FAILED WRITE\n");
        }

        printf("** TEST: readfile (RUN %d/%d) **\n\n", repeats, repeatTimes);
        repeats++;
    }
    printf("---- END: 1-5 TESTS ----\n\n");

    if (othertests == 1)
    {
        int nonexistRead = 0;
        struct pokemon nonexistPokebank[5];
        int nonexistPokemonNum = 5;
        /** read from non-exist file */
        printf("---- START: READ NON-EXISTENT FILE ----\n\n");
        printf("** TEST: readfile **\n");
        printf("* filename: nonexist.txt\n");
        nonexistRead = readfile(nonexistPokebank, &nonexistPokemonNum, "nonexist.txt");
        if (nonexistRead == -1)
        {
            printf("* READ FILE ERRORED (GOOD!)\n");
        }
        else
        {
            printf("* READ FILE DIDN'T ERROR (BAD!)\n");
        }
        printf("** TEST: readfile **\n\n");
        printf("---- END: READ NON-EXISTENT FILE ----\n\n");
    }

    if (othertests == 1)
    {
        int spaceRead = 0;
        struct pokemon spacePokebank[3];
        int spacePokemonNum = 3;
        /** read without enough space in pokebank */
        printf("---- START: READ INTO SMALLER POKEBANK ----\n\n");
        printf("** TEST: readfile **\n");
        printf("* filename: %s\n", filename);
        spaceRead = readfile(spacePokebank, &spacePokemonNum, filename);
        if (spaceRead == -1)
        {
            printf("* READ FILE ERROR\n");
        }
        else
        {
            char matchtest[] = "true";
            int matching = 3 == spacePokemonNum;
            if (matching == 0)
            {
                sprintf(matchtest, "%s", "false");
            }
            printf("* numpokemons: %d\n", spacePokemonNum);
            printf("* matches size: %s\n", matchtest);
        }
        printf("** TEST: readfile **\n\n");
        printf("---- END: READ INTO SMALLER POKEBANK ----\n\n");
    }

    return 1;
}
