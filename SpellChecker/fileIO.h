/* Author: Samantha Taylor
 * Student ID: 18863152
 * Filename: fileIO.h
 * Purpose: Read and write files
 * As well as process files into correct format
 *
 * Assume filenames cannot be larger than 49 characters*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "settings.h"

/* Purpose: Creates a boolean type 
 * Used in if statements to determine if statement should run.
 * As well as while loops to determine when to stop. */
#ifndef TRUE_FALSE
#define TRUE_FALSE

    #define FALSE 0
    #define TRUE !FALSE

#endif

/* Defines the maximum length of letters to be inputted from the user*/
#define MAX_LENGTH 50

FILE* openFileRead(char*);
FILE* openFileWrite(char*);

Settings* readSettingsFile(char*);
LinkedList* readDictFile(char*);
LinkedList* readUserFile(char*);
Settings* readSettings(FILE*);

void writeUserFile(char*, int, char**);
void writeFile (FILE*, int, char**);

LinkedList* dictFileToList(FILE*);
LinkedList* userFileToList(FILE*);

char* copyWord(char*);

void closeFile(FILE*);
