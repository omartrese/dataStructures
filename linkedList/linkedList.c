#include "linkedList.h"

LinkedList newLinkedList(Type listType)
{
    LinkedList list;
    list.type = listType;
    list.head = NULL;
    return list;
}

void Add(LinkedList *list, void *value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
}