#include "linkedList.h"

int main()
{
    LinkedList myLinkedList = newLinkedList(INTEGER);
    int values[] = {5, 6, 7, 8, 9, 8, 3};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
    {
        int *val = malloc(sizeof(int));
        *val = values[i];
        Add(&myLinkedList, val);
    }


    PrintList(&myLinkedList);


    int value = *(int *)myLinkedList.head->value;
    printf("el head de la lista enlazada es: %d", value);
    // Limpieza
    freeList(myLinkedList);
    return 0;
}
