#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

typedef enum
{
    INTEGER,
    FLOAT,
    STRING
} Type;

typedef struct
{
    union value
    {
        int integer;
        float floating;
        char *string;
    };
    
    Node *next;
// [(head) (1) -next--> (2) -next--> (tail) (3)]
} Node;

typedef struct
{
    Type type;
    Node head;
    Node tail;

} LinkedList;

LinkedList newLinkedList(Type listType);
void Add(LinkedList *list, void *value);
void AddFirst(LinkedList *list, void *value);
void Search(LinkedList *list, void *value);
void RemoveAt(LinkedList *list, size_t index);
void Remove(LinkedList *list, void *value);

#endif
