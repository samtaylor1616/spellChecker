/* Author: Samantha Taylor
 * Date: 19/10/2017
 * Filename:linkedList.c
 *
 * Used fom Prac 6 Linked list */

#include "linkedList.h"

/* Name: createLinkedList
 * Import: Nothing
 * Export: A pointer to a malloced linked list
 * Malloc space for the linked list*/
LinkedList* createLinkedList()
{
    LinkedList* list = NULL;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

/* Name: addFirst
 * Import: Pointer to a linked list struct and data
 * Export: void
 * Purpose: Add data to the list passed in */
void addFirst(LinkedList* list, void* data)
{
    LinkedListNode* head = NULL;
    LinkedListNode* newNd;

    head = list->head;

    /* Create new node */
    newNd = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNd->data = NULL;
    newNd->next = NULL;
    newNd->data = data;

    if( head != NULL) /* List has elements */
    {
        newNd->next = head;
        list->head = newNd;
    }
    else/* List is empty */
    {   
        list->head = newNd;
        newNd->next = NULL;
        list->tail = newNd; 
    }
    list->length++;
}

/* Name: addLast
 * Import: Pointer to a linked list struct
 * Export: void
 * Purpose: Add data via a pointer to linked list*/
void addLast(LinkedList* list, void* data)
{
    LinkedListNode* tail = list->tail;
    /* Create new node */
    LinkedListNode* newNd = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNd->data = data;

    if(tail != NULL) /* List has elements */
    {
        tail->next = newNd;
        newNd->next = NULL;
        list->tail = newNd;
        list->length++;
    }
    else/* List is empty */
    {
        addFirst(list, data); 
    }
}

/* Name: removeFirst
 * Import: Pointer to the LinkedList
 * Export: void pointer to the data
 * Purpose: Return the removed LinkedListNode via a void pointer*/
void* removeFirst(LinkedList* list)
{
    LinkedListNode* removeNd;
    /* Check list has at least one element left in it*/
    if(list->length > 1)
    {
        removeNd = list->head;
        list->head = list->head->next;
        list->length--;
    }
    else if( list->length == 1) /* Only one element in list */
    {
        removeNd = list->head;
        list->head = NULL;
        list->tail = NULL;
        list->length--;
    }
    else /* List is empty*/
    {
        removeNd = NULL;
    }
    return removeNd->data;
}


/* Name: getElement
 * Import: Pointer to LinkedList
 *         Index of element we want to remove
 * Export: void pointer
 *          User type casts it to whatever datatype needed
 * Purpose: Find the element of the index number
 *          Returns NULL if index is out of bounds*/
void* getElement(LinkedList *list, int index)
{
    int ii;
    int length = list->length;
    LinkedListNode* currentNode;
    if( (index < length) && (index >= 0))
    {
        currentNode = list->head;
        for(ii = 0; ii < index; ii++)
        {
            currentNode = currentNode->next;
        }
    }
    else
    {
        currentNode = NULL;
        currentNode->data = NULL;/* Index out of bounds*/
    }
    return currentNode->data;
}



/* Name: freeListData
 * Import: Pointer to a LinkedList
 * Export: nothing
 * Purpose: To free list through iteration (REMOVES DATA)*/
void freeListData(LinkedList* list)
{
    LinkedListNode *currentNode;
    LinkedListNode *nextNode;

    currentNode = list->head;

    while(currentNode != NULL)
    {
        nextNode = currentNode->next;
        free(currentNode->data);
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);
}

/* Name: freeList
 * Import: Pointer to a LinkedList
 * Export: nothing
 * Purpose: To free list through iteration (DOES NOT REMOVE DATA)*/
void freeList(LinkedList* list)
{
    LinkedListNode *currentNode;
    LinkedListNode *nextNode;

    currentNode = list->head;

    while(currentNode != NULL)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);
}
