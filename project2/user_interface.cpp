/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 12, 2023
//
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:
//   This is the user interface component to the
//   bank database application, which handles data
//   entry and parsing of that data to be added
//   into the database.
//
 ****************************************************************/

#include <iostream>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This is the entrypoint to the user interface,
//                 which handles validation of user input and has
//                 auto-complete for command options. For debugging,
//                 the user can pass in the "debug" parameter to
//                 see what is being done in the database.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  1 : success
//
 ****************************************************************/
int main () {
    // Say HelloWorld five times
    for (int index = 0; index < 5; ++index)
      std::cout << "HelloWorld!" << std::endl;
    char input = 'i';
    std::cout << "To exit, press 'm' then the 'Enter' key." << std::endl;
    std::cin  >> input;
    while(input != 'm') {
        std::cout << "You just entered '" << input << "'. "
             << "You need to enter 'm' to exit." << std::endl;
        std::cin  >> input;
    }
    std::cout << "Thank you. Exiting." << std::endl;
    return 0;
}