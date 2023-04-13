/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 31, 2023
//
//  FILE:        homework8.c
//
//  DESCRIPTION:
//   This program reads binary data of a TCP header from a file,
//   then generates a response header and prints it to a file.
//
 ****************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void printheader(const unsigned char []);
void makeheader(const unsigned char [], unsigned char []);

int readfile(const char [], unsigned char []);
int writefile(const char [], const unsigned char []);

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
    unsigned char header[20];

    readfile("request3.bin", header);
    writefile("request3test.bin", header);

    std::cout << header << std::endl;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   This function prints the data found from the TCP header.
//
//  Parameters:    header (const unsigned char []) : the TCP header data.
//
//  Return values:  void
//
 ****************************************************************/

void printheader(const unsigned char header[])
{
    std::cout << "print" << std::endl;
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   This function makes a TCP header from a header array.
//
//  Parameters:    header (const unsigned char []) : the TCP header data.
//                 returnHeader (unsigned char []) : the created TCP header data.
//
//  Return values:  void
//
 ****************************************************************/

void makeheader(const unsigned char header[], unsigned char returnHeader[])
{
    std::cout << "make" << std::endl;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   This 
//
//  Parameters:    filename (const char [])  : the binary file to read
//                 header (unsigned char []) : the read TCP header data.
//
//  Return values:  0 : successfully read data
//                 -1 : an error occured
//
 ****************************************************************/

int readfile(const char filename[], unsigned char header[])
{
    FILE * pFile;
    int success = -1;

    pFile = fopen(filename, "rb");
    if (pFile != NULL) {
        int result = fread(header, sizeof(unsigned char), sizeof(unsigned char) * 20, pFile);
        if (result == sizeof(unsigned char) * 20) { 
            success = 0;
        }

        fclose (pFile);
    }
    
    return success;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   This
//
//  Parameters:    filename (const char [])  : the binary file to write to
//                 header (unsigned char []) : the TCP header data to write
//
//  Return values:  0 : successfully written data
//                 -1 : an error occured
//
 ****************************************************************/

int writefile(const char filename[], const unsigned char header[])
{
    FILE * pFile;
    int success = -1;

    pFile = fopen(filename, "wb");
    if (pFile != NULL) {
        int result = fwrite(header, sizeof(unsigned char), sizeof(unsigned char) * 20, pFile);
        if (result == sizeof(unsigned char) * 20) { 
            success = 0;
        }

        fclose (pFile);
    }
    
    return success;
}
