#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    INTEGER,
    FLOAT,
    STRING
} Type;

typedef struct Node
{
    void *value;
    struct Node *next;
} Node;

typedef struct
{
    Type type;
    Node *head;
} LinkedList;

LinkedList newLinkedList(Type listType);
bool Exists(LinkedList list, void *value);
void PrintList(LinkedList *list);
void Add(LinkedList *list, void *value);
void AddLast(LinkedList *list, void *value);
void RemoveAt(LinkedList *list, size_t index);
void Remove(LinkedList *list, void *value);
void freeList(LinkedList *list); 

#endif
