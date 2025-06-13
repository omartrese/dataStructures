#include "linkedList.h"

LinkedList newLinkedList(Type listType)
{
    LinkedList list;
    list.type = listType;
    list.head = NULL;
    return list;
}

bool Exists(LinkedList list, void *value)
{
    Node *current = list.head;

    while (current != NULL)
    {
        switch (list.type)
        {
        case INTEGER:
            if (*(int *)current->value == *(int *)value)
                return true;
            break;
        case FLOAT:
            if (*(float *)current->value == *(float *)value)
                return true;
            break;
        case STRING:
            if (strcmp((char *)current->value, (char *)value) == 0)
                return true;
            break;
        }
        Node *next = current->next;
        current = next;
    }
    return false;
}

void PrintList(LinkedList *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        switch (list->type)
        {
        case INTEGER:
            printf("%d ", *(int *)current->value);
            break;
        case FLOAT:
            printf("%.2f ", *(float *)current->value);
            break;
        case STRING:
            printf("%s ", (char *)current->value);
            break;
        }
        current = current->next;
    }
    printf("\n");
}

void Add(LinkedList *list, void *value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
}

void AddLast(LinkedList *list, void *value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void RemoveAt(LinkedList *list, size_t index)
{
    if (!list->head)
        return;

    Node *current = list->head;
    Node *prev = NULL;

    for (size_t i = 0; i < index && current != NULL; i++)
    {
        prev = current;
        current = current->next;
    }

    if (!current)
        return; // índice fuera de rango

    if (prev == NULL)
    {
        // Eliminar el head
        list->head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current->value);
    free(current);
}

void Remove(LinkedList *list, void *value)
{
    Node *current = list->head;
    while (current != NULL)
    {
        Node *next = current->next;
        bool removeNode = false;
        switch (list->type)
        {
        case INTEGER:
            if (*(int *)current->value == *(int *)value)
                removeNode = true;
            break;
        case FLOAT:
            if (*(float *)current->value == *(float *)value)
                removeNode = true;
            break;
        case STRING:
            if (strcmp((char *)current->value, (char *)value) == 0)
                removeNode = true;
            break;
        }
        if (removeNode)
        {
            if (current == list->head)
            {
                list->head = current->next;
                free(current->value);
                free(current);
                current = list->head;
            }
            else
            {
                Node *prev = list->head;
                while (prev->next != current)
                    prev = prev->next;
                prev->next = current->next;
                free(current->value);
                free(current);
                current = prev->next;
            }
        }
        else
        {
            current = next;
        }
    }
}

void freeList(LinkedList *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
}
