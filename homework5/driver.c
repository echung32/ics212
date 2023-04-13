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
    int repeats = 0;
    int randomamount;
    int randomname;
    char filename[] = "pokebank.txt";
    char * name[] = {"Pikachu", "Pichu", "Bulbasaur", "Charmander", "Raichu", "Squirtle"};

    /** to initialize random number generator */
    srand(time(NULL));
    
    /** repeat random test 5 times */
    printf("---- START: RANDOM TESTS ----\n\n");
    while (repeats++ < 5)
    {
        int readwritesuccess = -1;
        
        struct pokemon pokemonbank[5];
        int numpokemons;

        int index = 0;
        struct pokemon pokemonbank_2[5];
        int numpokemons_2;

        /** to bring it down to 1 digit, then bring it between 0-5 */
        randomamount = (rand() % 10) % 6;

        printf("** TEST: writefile (RUN %d/5) **\n", repeats);
        printf("* filename: %s\n", filename);
        printf("* randomamount: %d\n", randomamount);
        while (numpokemons < randomamount)
        {
            randomname = (rand() % 10) % 6;

            pokemonbank[numpokemons].level = rand() % 100;
            strncpy(pokemonbank[numpokemons].name, name[randomname], 30);
            printf("* CREATE POKEMON (%d/%d):\n", numpokemons + 1, randomamount);
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

        printf("** TEST: writefile (RUN %d/5) **\n\n", repeats);

        printf("** TEST: readfile (RUN %d/5) **\n", repeats);
        printf("* filename: %s\n", filename);

        if ( readwritesuccess == 0 )
        {
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

        printf("** TEST: readfile (RUN %d/5) **\n\n", repeats);
    }
    printf("---- END: RANDOM TESTS ----\n\n");

    /** read from non-exist file */
    printf("---- START: READ NON-EXISTENT FILE ----\n\n");
    /** scope hack, so that variables can be neater */
    if (0 == 0)
    {
        int nonexistRead = 0;
        struct pokemon nonexistPokebank[5];
        int nonexistPokemonNum;
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
    }

    printf("---- END: READ NON-EXISTENT FILE ----\n\n");
    
    /** read without enough space in pokebank */
    printf("---- START: READ INTO SMALLER POKEBANK ----\n\n");
    /** scope hack, so that variables can be neater */
    if (0 == 0)
    {
        int spaceRead = 0;
        struct pokemon spacePokebank[3];
        int spacePokemonNum;
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
    }

    printf("---- END: READ INTO SMALLER POKEBANK ----\n\n");

    return 1;
}
