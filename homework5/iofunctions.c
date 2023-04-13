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
//   This file contains the read/write logic that interacts directly
//   with the filesystem. This is the only file that should directly
//   interact with the filesystem.
//
****************************************************************/

#include <stdio.h>
#include "pokemon.h"

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes the provided pokearray struct into a file.
//                 If a file already exists with the filename provided,
//                 it will overwrite the existing file with new data.
//
//  Parameters:    pokearray (struct pokemon[]) : The data of the pokemons
//                                                to be written to disk.
//                 num (int) : The size of the pokemon array.
//                 filename (char[]) : The name of the file to write to.
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
            /** convert the integer into a string. */
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
//  Parameters:    pokearray (struct pokemon[]) : The data from the file
//                                                will be written to this struct.
//                 num (int) : The size of the pokemon array read.
//                             This is not representative of the amount
//                             of pokemons in the actual file, only the amount
//                             that could be written to the pokearray.
//                 filename (char[]) : The name of the file to read from.
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

        while ( index < *num && scanned != EOF )
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
