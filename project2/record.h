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
//  FILE:        record.h
//
//  DESCRIPTION:
//   The data structure of a Record struct.
//
 ****************************************************************/

#ifndef RECORD_H
#define RECORD_H
struct record
{
    int                accountno;
    char               name[30];
    char               address[50];
    struct record*     next;
};
#endif