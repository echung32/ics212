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
    int success;
    const char *readfilename[3] = {"request1.bin", "request2.bin", "request3.bin"};
    const char *writefilename[3] = {"response1.bin", "response2.bin", "response3.bin"};

    for (int i = 0; i < 3; i++)
    {
        unsigned char header[20];
        unsigned char newheader[20];

        success = readfile(readfilename[i], header);
        if (success == 0)
        {
            std::cout << readfilename[i] << " - read - " << header << std::endl;
        }

        success = writefile(writefilename[i], header);
        if (success == 0)
        {
            std::cout << writefilename[i] << " - write - " << header << std::endl;
        }

        /** printheader(header); */ 
        makeheader(header, newheader);
    }

    return success;
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
    /** 2 bytes */
    int source, destination;
    /** 4 bytes */
    unsigned int sequence, acknowledgement;
    /** 1 bit */
    const char *control[6] = {"FIN", "SYN", "RST", "PSH", "ACK", "URG"};

    source = header[1] << 8 | header[0];
    destination = header[3] << 8 | header[2];
    sequence = header[7] << 24 | header[6] << 16 | header[5] << 8 | header[4];
    acknowledgement = header[11] << 24 | header[10] << 16 | header[9] << 8 | header[8];

    printf("Source: %d\n", source);
    printf("Destination: %d\n", destination);
    printf("Sequence: %u\n", sequence);
    printf("Acknowledgement: %u\n", acknowledgement);

    printf("Control bits which are set to 1:\n");
    for (int i = 6; i > 0; i--)
    {
        if ((header[13] & (1 << (i - 1))) != 0)
        {
            printf("%s\n", control[i - 1]);
        }
    }
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
    /** 2 bytes */
    int source, destination;
    /** 4 bytes */
    unsigned int sequence, acknowledgement;
    /** 1 bit */
    const char *control[6] = {"FIN", "SYN", "RST", "PSH", "ACK", "URG"};
    int bitmask_32768 = 1 << 15;

    /** copy header to returnHeader */
    for (int i = 0; i < 20; i++)
    {
        returnHeader[i] = header[i];
    }

    source = returnHeader[1] << 8 | returnHeader[0];
    destination = returnHeader[3] << 8 | returnHeader[2];
    sequence = returnHeader[7] << 24 | returnHeader[6] << 16 | returnHeader[5] << 8 | returnHeader[4];
    acknowledgement = returnHeader[11] << 24 | returnHeader[10] << 16 | returnHeader[9] << 8 | returnHeader[8];

    /** check greater than 32768 */
    if ((source & bitmask_32768) != 0)
    {
        int bitmask_4th = 1 << 5;
        int bitmask_11th = 1 << (12 - 8);

        returnHeader[0] ^= bitmask_4th;
        returnHeader[1] ^= bitmask_11th;

        printf("GREATER!!\n");
    }

    /** set the destination to the source */
    returnHeader[2] = returnHeader[0];
    returnHeader[3] = returnHeader[1];
    /** header source has the destination, copy from there. */
    returnHeader[0] = header[2];
    returnHeader[1] = header[3];

    /** set acknowledgement number to sequence number */
    returnHeader[11] = header[7];
    returnHeader[10] = header[6];
    returnHeader[9] = header[5];
    returnHeader[8] = header[4];

    printheader(returnHeader);
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   This function reads a binary file and writes the
//                 contents read into the header variable.
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
    if (pFile != NULL)
    {
        int result = fread(header, sizeof(unsigned char), sizeof(unsigned char) * 20, pFile);
        if (result == sizeof(unsigned char) * 20)
        { 
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
//  DESCRIPTION:   This function takes the data from the header variable
//                 and writes it to a binary file.
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
    if (pFile != NULL)
    {
        int result = fwrite(header, sizeof(unsigned char), sizeof(unsigned char) * 20, pFile);
        if (result == sizeof(unsigned char) * 20)
        { 
            success = 0;
        }

        fclose (pFile);
    }

    return success;
}
