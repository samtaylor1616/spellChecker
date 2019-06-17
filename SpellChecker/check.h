/**
 * UNIX & C Programming (COMP1000) Assignment - Spell checking code.
 *
 * UPDATED check.h file
 */

#ifndef TRUE_FALSE
#define TRUE_FALSE

    #define FALSE 0
    #define TRUE !FALSE

#endif

#ifndef CHECK_H
#define CHECK_H

typedef int (*ActionFunc)(char* word, char* suggestion);

void check(char* text[], int textLength, 
           char* dict[], int dictLength, 
           int maxDifference, ActionFunc action);

#endif

