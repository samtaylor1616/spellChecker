/* Author: Samantha Taylor
 * Student ID: 18863152
 * Filename: settings.h
 * Purpose: Contains functions and containers for elements related to the settings file*/

#include <string.h>
#include <stdio.h>

#ifndef SETTINGS
#define SETTINGS

    /* Char pointer containing the name of the dictionary file being used
     * Integer representing the maximum allowed difference between a misspelt word and any corrections found
     * Char pointer representing if auto correct will be used (yes/no) */
    typedef struct
    {
        char filename[50];
        int maxDiff;
       char autoCorrect[4]; 
    }Settings;
#endif

#ifndef TRUE_FALSE
#define TRUE_FALSE

    #define FALSE 0
    #define TRUE !FALSE

#endif

int autoCheck(char*, char*);
int userCheck(char*, char*);
int isNull(char*);
