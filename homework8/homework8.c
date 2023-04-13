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
    ...
}

/*****************************************************************
//
//  Function name: foo
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

int foo(int bar)
{
    ...
}
