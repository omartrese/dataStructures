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

void PrintList(LinkedList *list)
{
    Node *curr = list->head;
    while (curr != NULL)
    {
        switch (list->type)
        {
        case INTEGER:
            printf("%d ", *(int *)curr->value);
            break;
        case FLOAT:
            printf("%.2f ", *(float *)curr->value);
            break;
        case STRING:
            printf("%s ", (char *)curr->value);
            break;
        }
        curr = curr->next;
    }
    printf("\n");
}

void freeList(LinkedList list) 
{
    Node *current = list.head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current->value);
        free(current);
        current = next;
    }

}
