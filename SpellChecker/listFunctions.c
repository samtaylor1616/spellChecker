/* Author: Samantha Taylor
 * Student ID: 18863152
 * Filename: listFunctions.c
 * Purpose: Contains functions that list can preform*/

#include "listFunctions.h"

/* Name: listToArray
 * Import: Pointer to a linked list struct
 * Export: char pointer to a pointer
 * Purpose: Converts a list of words into an array of strings */
char** listToArray(LinkedList* list)
{
    int ii = 0, jj = 0;
    char ** array = NULL;
    LinkedListNode* current = NULL;
    int length = 0;

    if( list != NULL)
    {
        length = list->length;

        array = (char**)malloc( length * sizeof(char*) );
        for(jj = 0; jj < length; jj++)
        {
            array[jj] = NULL;
        }

        current = list->head;
        while( current != NULL )
        {
            char * addWord = NULL;
            addWord = (char*)current->data;

            array[ii] = addWord;
            if( current->next != NULL)
            {
                current = current->next;
            }
            else
            {
                current = NULL;
            }
            ii++;
        }
    }
    else
    {
        printf("List is NULL\n");
    }
    return array;
}

/* Name: printList
 * Imports: Pointer to a list
 * Export: Nothing
 * Purpose: Prints each entry in linkedList*/
void printList(LinkedList* list)
{
    LinkedListNode* current = NULL;
    current = (list->head);

    if(current == NULL)
    {
        printf("Current NULL\n");
    }
    while(current != NULL)
    {
        printf( "%s\n",(char*)(current->data) );
        if(current->next != NULL)
        {
            current = current->next;
        }
        else
        {
            current = NULL;
        }
    }
}


