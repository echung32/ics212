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
//  FILE:        database.h
//
//  DESCRIPTION:
//   The function prototypes of the database.c file.
//
 ****************************************************************/

void addRecord(struct record **, int, char[], char[]);
void printAllRecords(struct record *);
int findRecord(struct record *, int);
int deleteRecord(struct record **, int);
int writefile(struct record *, char[]);
int readfile(struct record **, char[]);
void cleanup(struct record **);
