/* Author: Samantha Taylor
 * Student ID: 18863152
 * Filename: TestHarness.c*/
#include "listFunctions.h"
#include <string.h>

void listFunctionsTest();
void listToArrayTest();
void printListTest();



int main (int argc, char * argv[])
{
    listFunctionsTest();
    return 0;
}

void listFunctionsTest()
{
    listToArrayTest();
/*    printListTest();*/
}

void listToArrayTest()
{
    LinkedList* input = createLinkedList(); 
    char * expected[] = { "top", "toothpicks", "tooths" };
    char ** actual = NULL;
    int ii = 0;

    /* Order: top, toothpicks, tooths*/
    addFirst(input, "tooths");
    addFirst(input, "toothpicks");
    addFirst(input, "top");

    actual = listToArray(input);
    for(ii = 0; ii < 3; ii++)
    {
        if( strcmp(expected[ii], actual[ii]) != 0)
        {
            printf("FAIL: listToArray %d == %s\n", ii, actual[ii]);
        }
        else
        {
            printf("Successfull!\n");
        }
    }


free(actual);
}
