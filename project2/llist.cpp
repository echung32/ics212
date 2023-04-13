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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This is the database component to the bank database
//   application, which handles the methods used to
//   add, print, find, and delete records within the
//   database.
//
 ****************************************************************/
 
#include "llist.h"
#include "record.h"

llist::list()
{
  this.start = NULL;
  this.filename = "database.txt";
}

llist::list(char filename[])
{
  llist::list();
  this.filename = filename;
}

llist::~list()
{
}

void llist::addRecord(int uaccountno, char uname[],char uaddress[])
{
}

int llist::findRecord(int uaccountno)
{
  return 1;
}

void llist::printAllRecords()
{
}

int llist::deleteRecord(int uaccountno)
{
  return 1;
}

int llist::writefile()
{
  return 1;
}

int llist::readfile()
{
  return 1;
}

