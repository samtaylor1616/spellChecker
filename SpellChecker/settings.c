/* Author: Samantha Taylor
 * Student ID: 18863152
 * Filename: settings.c
 *
 * Interact with check.h typedef action pointer */

#include "settings.h"

/* Name: autoCheck
 * Import: Char pointer, char pointer
 * Export: Integer
 * Purpose: Returns True unless suggestion is NULL*/
int autoCheck(char* word, char * suggestion)
{
    int change = TRUE;
    if( isNull(suggestion) == TRUE || strcmp(word, suggestion) == 0)
    {
        change = FALSE;
    }
    else
    {
        printf("%s has been changed to %s\n", word, suggestion);
    }
    return change;
}

/* Name: userCheck
 * Import: Char pointer, char pointer
 * Export: Integer
 * Purpose: Asks the user if they want to change the first import to be the second
 * Returns TRUE if yes
 * Checks suggestion is not equal to NULL, otherwise returns FALSE*/
int userCheck(char* word, char * suggestion)
{
    int change = FALSE;
    /* Checks suggestion contains a word */
    if( isNull(suggestion) != TRUE )
    {
        char choice[20];
        printf("Did you mean %s instead of %s?\nType yes to change or anything else to retain original word\n", suggestion, word);
                        
        scanf("%s", choice);
        fflush(stdin);
        if( strcmp(choice, "yes") == 0)
        {
            change = TRUE;
        }
    }
    return change;
}

/* Name: isNull
 * Import: Char pointer
 * Export: Interger
 * Purpose: Check if the word passed to function is equal to NULL*/
int isNull(char* word)
{
    int isNull = TRUE;
    if(word != NULL)
    {
        isNull = FALSE ;
    }
    return isNull;
}
