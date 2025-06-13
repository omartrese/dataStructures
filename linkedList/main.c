#include "linkedList.h"

int main()
{
    LinkedList myLinkedList = newLinkedList(INTEGER);
    int values[] = {7, 6, 7, 8, 9, 8, 3};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) //test 0 --> create new linked list
    {
        int *val = malloc(sizeof(int));
        *val = values[i];
        Add(&myLinkedList, val);
    }

    PrintList(&myLinkedList); //test 1 --> print list

    int value = *(int *)myLinkedList.head->value;
    printf("el head de la lista enlazada es: %d\n", value);

    printf(Exists(myLinkedList, &(int){70}) ? "Existe el número 70\n" : "que va, aqui no hay na\n"); //test 2 --> check if value exists within the list

    RemoveAt(&myLinkedList, 3);

    PrintList(&myLinkedList);

    Remove(&myLinkedList, &(int){7});

    PrintList(&myLinkedList);

    AddLast(&myLinkedList, &(int){84});

    PrintList(&myLinkedList);

    freeList(&myLinkedList); //final test --> free linked list from memory 
    return 0;
}
