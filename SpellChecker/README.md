Instructions for using prgram:
    '.spellconf' file contains settings for the spell checker
    Format of file:
        dictfile= "dictFile.txt"
        maxdifference = integer
        autoCorrect= yes/no

    Run the program giving a single command-line parameter of the file you want to get spell check.

    **WARNING: File is overwritten once the spell checker has finished. File format may differ.**

List of files and their purposes:
    Main: Runs a spell checker on a file given by the user via command-line parameter
    Settings: Contains information and functions relating to the setting file for the program
    LinkedList: Provides a structure to store and access related information
    FileIO: Reads and writes files. Also processes files contents into correct information containers
    ListFunctions: Provides methods that provide functionality to a list
