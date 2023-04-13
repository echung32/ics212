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
//  FILE:        database.h
//
//  DESCRIPTION:
//   The function prototypes of a Database.
//
 ****************************************************************/

void addRecord (struct record **, int, char [ ],char [ ]);
void printAllRecords(struct record *);
int findRecord (struct record *, int);
int deleteRecord(struct record **, int);

