/* Author: Samantha Taylor
 * Date: 27/09/2017
 * Filename: linkedList.h
 * Purpose: Provides a structure to data we are storing
 *
 * Used from submitted Prac 6 structs and Linked Lists*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Purpose: Generic LinkedListNode (Any data can be stored into node)
 * How it works: Has a pointer to the data related to node.
 *      As well as a LinkedListNode* struct pointer to the next Node creating a link between nodes
 * Relates to the LinkedList struct
 * The LinkedList struct has many pointers to LinkedListNode structs */
#ifndef LIST_NODE
    #define LIST_NODE
    typedef struct LinkedListNode{
        void* data;
        struct LinkedListNode* next;
    }LinkedListNode;
#endif


/* Purpose: LinkedList (holds information of list)
 * How it works: Has a LinkedListNode struct pointer pointing to the first node of the list
 *      Similar there is a tail pointer option (pointing to the last node of the list)
 * Relates to the LinkedListNode struct by containing many instances of the struct inside
 * this LinkedList struct */
#ifndef LINKED_LIST
    #define LINKED_LIST
    typedef struct{
        LinkedListNode *head;
        LinkedListNode *tail;
        int length;
    }LinkedList;
#endif

LinkedList* createLinkedList();

void addFirst(LinkedList*, void*);
void addLast(LinkedList*, void*);

void* removeFirst(LinkedList*);

void* getElement(LinkedList*, int);

void freeListData(LinkedList*);
void freeList(LinkedList*);

