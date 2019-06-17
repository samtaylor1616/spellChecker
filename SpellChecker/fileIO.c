/* Author: Samantha Taylor
 * Student ID: 18863152
 * Filename: fileIO.c
 * Purpose: Read and write files
 * As well as process files into correct format*/

#include "fileIO.h"


/* ______________________________ Reading methods __________________________________________ */

/* Name:openFileRead
 * Import: Name of file to read
 * Export: A pointer to a file to read
 * Purpose: Open a file with read permissions*/
FILE* openFileRead(char* filename)
{
    FILE* sourceFile = NULL;
    sourceFile = fopen(filename, "r");
    
    if(sourceFile == NULL)
    {
        perror("Error opening file to read to");
    }
    return sourceFile;
}

/* Name: readSettingsFile
 * Import: Name of settings file
 * Export: Struct containing setting information
 * Purpose: Opens and closes settings file, Sets up program settings */
Settings* readSettingsFile(char* filename)
{
    FILE* sourceFile = NULL;
    Settings * settings = NULL;
    sourceFile = openFileRead(filename);

    if(sourceFile != NULL)
    {
        settings = readSettings(sourceFile);
        closeFile(sourceFile);
    }

    return settings;
}

/* Name: readDictFile
 * Import: Name of dictionary file
 * Export: Pointer to a LinkedList struct
 * Purpose: Exports a list containing dictionary contents*/
LinkedList* readDictFile(char* filename)
{
    FILE* sourceFile = NULL;
    LinkedList* list = NULL;
    sourceFile = openFileRead(filename);

    if(sourceFile != NULL)
    {
        list = dictFileToList(sourceFile);
        closeFile(sourceFile);
    }

    return list;
}

/* Name: readUserFile
 * Import: Name of file user imported
 * Export: Pointer to a LinkedList struct
 * Purpose: Exports a list containing file contents
 * (Each word in one node) */
LinkedList* readUserFile(char* filename)
{
    FILE* sourceFile = NULL;
    LinkedList* list = NULL;
    sourceFile = openFileRead(filename);

    if(sourceFile != NULL)
    {
        list = userFileToList(sourceFile);
        closeFile(sourceFile);
    }

    return list;
}

/* Name: readSettings
 * Import: File pointer to a settings file
 * Export: Settings struct
 * Purpose: Check file format is correct 
 * Then reads in the settings content into a struct
 * File format: 
 *   dictfile= ...
 *   maxdifference= ...
 *   autocorrect= ... */
Settings* readSettings(FILE* settingsFile)
{
    int nReads = 0;
    Settings* settings = NULL;
    settings = (Settings*)malloc(sizeof(Settings));

    nReads = fscanf( settingsFile, "dictfile= %50s ", settings->filename);
    if(nReads != 1)
    {
        perror("\nError reading in the settings file.\nCheck dictionary filename: \n\tdictfile= \"dictFilename.txt\"");
        settings = NULL;
    }

    nReads = fscanf( settingsFile, "maxdifference= %d ", &(settings->maxDiff));
    if(nReads != 1)
    {
        perror("\nError reading in the settings file.\nCheck maxDifference: \n\tmaxDifference= someInteger");
        settings = NULL;
    }
    nReads = fscanf( settingsFile, "autocorrect= %3s ", settings->autoCorrect);
    if(nReads != 1)
    {
        perror("\nError reading in the settings file.\nCheck autocorrect: \n\tautocorrect= yes/no");
        settings = NULL;
    }

    if(settings == NULL)
    {
        free(settings);
    }
    return settings;
}

/* Name: dictFileToList
 * Import: Pointer to an opened file
 * Export: Pointer to a linked list
 * Purpose: Reads each word dictionary file into a linked list node*/
LinkedList* dictFileToList(FILE* filename)
{
    LinkedList* list = NULL;
    char* word = NULL;
    char * copiedWord = NULL;
    int done = FALSE;
    int length = 0;

    list = createLinkedList();
    word = (char*)malloc( MAX_LENGTH * sizeof(char) );

    while( done == FALSE )
    {
        if(fgets(word, MAX_LENGTH, filename) != NULL)
        {
            length = strlen(word) - 1; /* remove newline */

            copiedWord = (char*)calloc( (length + 1), sizeof(char) );
            copiedWord = strncpy( copiedWord, word, length);

            addFirst(list, copiedWord);
        }
        else
        {
            /* END OF FILE */
            done = TRUE;
        }
    }

    free(word);
    return list;
}

/* Name: userFileToList
 * Import: Pointer to an opened file
 * Export: LinkedList pointer
 * Purpose: Read*/
LinkedList* userFileToList(FILE* filename)
{
    LinkedList* list = NULL;
    int nReads = 0;
    char word[MAX_LENGTH];
    char * copiedWord = NULL;
    int done = FALSE;

    list = createLinkedList();

    while(done == FALSE)
    {
        nReads = fscanf(filename, "%49s ", word);
        if(nReads == 1)
        {
            copiedWord = copyWord( word );
            addFirst(list, copiedWord);
        }
        else
        {
            done = TRUE; 
            /* Checks that no errors occured in the opened file */
            if(ferror(filename))
            {
                perror("Error reading from user file\n");
            }
        }

    }
    return list;
}
/* ______________________________ Writing methods __________________________________________ */

/* Name:openFileWrite
 * Import: Name of file to write to
 * Export: A pointer to a file 
 * Purpose: Open a file with write permissions*/
FILE* openFileWrite(char* filename)
{
    FILE* destFile = NULL;
    destFile = fopen(filename, "w");

    if(destFile == NULL)
    {
        perror("Error opening file to write to");
    }
    return destFile;
}

/* Name: writeUserFile
 * Import: Name of the file to write out to
 *         Number of words in array
 *         and Array of strings
 * Export: void
 * Purpose: Writes array of strings out */
void writeUserFile(char* outFilename, int numWords, char** wordArray)
{
    FILE* destFile = NULL;
    destFile = openFileWrite(outFilename);
    if(destFile != NULL)
    {
        writeFile(destFile,numWords, wordArray);
        closeFile(destFile);
    }
    else
    {
        if(ferror(destFile))
        {
            perror("Error writing out to a file");
        }
    }
}

/* Name: writeFile
 * Import: Pointer to a file,
 *         Number of words to write
 *         and a pointer to a pointer of chars
 * Export: void
 * Purpose: Write an array of strings out to file*/
void writeFile (FILE* outfile, int numWords , char** wordArray)
{
    int ii = 0;
    for(ii = 0; ii < numWords; ii++)
    {
        fprintf(outfile,"%s ", wordArray[ii]);
    }
}

/* ______________________________ Other methods __________________________________________ */
/* Name: copyWord
 * Import: Char array
 * Export: Char array
 * Purpose: Copy the contents of the imported
          * string into a correctly sized string */
char* copyWord(char* word)
{
    char* copiedWord = NULL;
    int length = strlen(word) + 1;

    copiedWord = (char*)malloc( length * sizeof(char) );

    copiedWord = strncpy( copiedWord, word, length);
     return copiedWord;
}

/* Name: closeFile
 * Import: Pointer to the file open
 * Export: none
 * Purpose: Close the file*/
void closeFile(FILE* fileToClose)
{
    fclose(fileToClose);
}
