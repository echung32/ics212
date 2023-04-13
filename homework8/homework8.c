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

#include <stdio.h>
#include <stdlib.h>

void printheader(const unsigned char[]);
void makeheader(const unsigned char[], unsigned char[]);

int readfile(const char[], unsigned char[]);
int writefile(const char[], const unsigned char[]);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This function reads data from three header request
//                 files, then creates a response to the request. Then,
//                 the response header is written to a file and printed
//                 to the terminal.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : successfully read and wrote the binary data
//                 -1 : an errored occured
//
 ****************************************************************/

int main(int argc, char* argv[])
{
    int success = 0;
    const char *readfilename[3] = {"request1.bin", "request2.bin", "request3.bin"};
    const char *writefilename[3] = {"response1.bin", "response2.bin", "response3.bin"};
    int repeatsIndex = 0;

    for (; repeatsIndex < 3; repeatsIndex++)
    {
        int i = repeatsIndex;
        unsigned char header[20];
        unsigned char newheader[20];

        success = readfile(readfilename[i], header);
        if (success == 0)
        {
            printf("read %s: %s\n", readfilename[i], header);
        }
        else
        {
            success = -1;
        }

        makeheader(header, newheader);

        success = writefile(writefilename[i], newheader);
        if (success == 0)
        {
            printf("write %s: %s\n", writefilename[i], newheader);
        }
        else
        {
            success = -1;
        }

        printf("\n>> printing request header\n");
        printheader(header);
        printf("\n>> printing response header\n");
        printheader(newheader);
        printf("\n-----------\n");
    }

    return success;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   This function prints the data found from the TCP header,
//                 in a human-readable format.
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
    int controlIndex = 6;
    source = header[1] << 8 | header[0];
    destination = header[3] << 8 | header[2];
    sequence = header[7] << 24 | header[6] << 16 | header[5] << 8 | header[4];
    acknowledgement = header[11] << 24 | header[10] << 16 | header[9] << 8 | header[8];

    printf("Source: %d\n", source);
    printf("Destination: %d\n", destination);
    printf("Sequence: %u\n", sequence);
    printf("Acknowledgement: %u\n", acknowledgement);

    printf("Control bits which are set to 1:\n");
    for (; controlIndex > 0; controlIndex--)
    {
        if ((header[13] & (1 << (controlIndex - 1))) != 0)
        {
            printf("%s\n", control[controlIndex - 1]);
        }
    }
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   This function makes a TCP header response from abort
//                 TCP request.
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
    int source = header[1] << 8 | header[0];
    /** 4 bytes */
    unsigned int sequence = header[7] << 24 | header[6] << 16 | header[5] << 8 | header[4];
    int bitmask_32768 = 1 << 15;
    int copyIndex = 0;

    /** copy header to returnHeader */
    for (; copyIndex < 20; copyIndex++)
    {
        returnHeader[copyIndex] = header[copyIndex];
    }

    /** check greater than 32768 */
    if ((source & bitmask_32768) != 0)
    {
        int bitmask_4th = 1 << 5;
        /** 11th considering the entire source */
        int bitmask_11th = 1 << (12 - 8);

        returnHeader[0] ^= bitmask_4th;
        returnHeader[1] ^= bitmask_11th;
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

    /** increment 1 to sequence number */
    sequence++;

    /**
     * 255 creates 11111111, then it is left shifted to a 4-byte length.
     * After & with the original sequence, it is right shifted to match
     * the 1-byte length so we can put it back in place in the array.
     */

    returnHeader[7] = (sequence & (255 << 24)) >> 24;
    returnHeader[6] = (sequence & (255 << 16)) >> 16;
    returnHeader[5] = (sequence & (255 << 8)) >> 8;
    returnHeader[4] = (sequence & (255));

    /** check if SYN is set, masking 2nd bit from right. */
    if ((header[13] & (1 << 1)) != 0)
    {
        /** set both SYN and ACK in response */
        returnHeader[13] = header[13] | (1 << 4);
    }
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   This function reads the data from a binary file,
//                 then saves it into the header variable passed.
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

        fclose(pFile);
    }

    return success;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   This function takes the data from the header variable,
//                 then saves it into a binary file.
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

        fclose(pFile);
    }

    return success;
}
