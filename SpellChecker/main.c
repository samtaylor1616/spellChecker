/* Author: Samantha Taylor
 * Student ID: 18863152
 * Filename: main.c
 * Purpose: Runs a spell check function that offers suggestions on a given user file*/

#include "main.h"
int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        Settings* settings = NULL;
        char* filename = NULL;
        LinkedList* dictList = NULL;
        char** dictArray = NULL;
        LinkedList * toCheckList = NULL;
        char** checkArray = NULL;
        ActionFunc action = NULL;

        filename = argv[1];

        /* read settings file -> into setting struct*/
        settings = readSettingsFile(".spellconf");
        if(settings != NULL)
        {

            /* read dictionary file -> each word into linked list (dictionary is one word per line) */
            dictList = readDictFile(settings->filename);

            if(dictList != NULL)
            {


                /* pass linked list into a dynamically-allocated array*/
                dictArray = listToArray(dictList);
                
                if( strcmp(settings->autoCorrect,"yes") == 0)
                {
                    action = &autoCheck;
                }
                else
                {
                    action = &userCheck;
                }                
                /* read the user file in the into a linked list */
         
                toCheckList = readUserFile(filename);
                
                if(toCheckList != NULL)
                {
            
                    /* pass linked list into a dynamically-allocated array*/
                    checkArray = listToArray(toCheckList);

                    /* Call the pre-existing function check() */
                    check(checkArray, toCheckList->length , dictArray, dictList->length, settings->maxDiff, action);
    
                    /* Write the user file array back to the user file*/
                    writeUserFile(filename, toCheckList->length, checkArray);

                    freeCharArray(checkArray, toCheckList->length);
                    freeList(toCheckList); /*Does not free list data*/
                }
                else
                {
                    printf("user file is empty.\n");
                }
                freeListData(dictList);
                free(dictArray); /* Data has been freed in above function*/
            }
            else
            {
                printf("Dictionary list is empty.\n");
            }


        }
        else
        {
            printf("Error occured in settings file.\n");
        }
            free(settings);
    }
    else
    {
        printf("\nError in command-line\nTry again entering a name of the file you wish to spell check.\n");
    }
    return 0;
}


/* Name: freeArray
 * Import: Pointer to a pointer of chars (Pointer to an array of strings)
 * Export: nothing
 * Purpose: To free array through iteration*/
void freeCharArray(char** array, int length)
{
    int ii = 0;
    for(ii = 0; ii < length; ii++)
    {
        free(array[ii]);
    }
    free(array);
}
