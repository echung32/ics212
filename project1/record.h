/*****************************************************************
//
//  NAME:        Ethan Chung
//
//  HOMEWORK:    project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 17, 2023
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
