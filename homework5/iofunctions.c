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
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#include <stdio.h>
#include "pokemon.h"

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : file successfully opened
//                 -1 : file failed to open
//
****************************************************************/

int writefile(struct pokemon pokearray[], int num, char filename[])
{
    FILE * ofile;
    int success = -1;

    ofile = fopen(filename, "w");
    if (ofile != NULL)
    {
        int index = 0;
        while ( index < num )
        {
            /** We need to convert the integer into a string. */
            char level[20];
            sprintf(level, "%d", pokearray[index].level);

            fputs(level, ofile);
            fputs("\n", ofile);
            fputs(pokearray[index].name, ofile);
            fputs("\n", ofile);

            index++;
        }
        fclose(ofile);
        success = 0;
    }

    return success;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Read a file formatted as a Pokemon file.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : file successfully opened
//                 -1 : file failed to open
//
****************************************************************/

int readfile(struct pokemon pokearray[], int* num, char filename[])
{
    FILE * ofile;
    int success = -1;

    ofile = fopen(filename, "r");
    if (ofile != NULL)
    {
        int index = 0;
        int scanned = 0;

        while ( index < sizeof(pokearray) && scanned != EOF )
        {
            scanned = fscanf(ofile, "%d\n%s", &pokearray[index].level, pokearray[index].name);

            /** Additional check to prevent improper index add. */
            if (scanned != EOF)
            {
                index++;
            }
        }

        *num = index;
        fclose(ofile);
        fflush(ofile);
        success = 0;
    }

    return success;
}
