/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 6, 2022
//
//  FILE:        record.h
//
//  DESCRIPTION:
//   The data structure of a Record.
//
 ****************************************************************/

struct record
{
    int                accountno;
    char               name[30];
    char               address[50];
    struct record*     next;
};
