#include "linkedList.h"

int main()
{
    LinkedList myLinkedList = newLinkedList(INTEGER);
    int values[] = {70, 6, 7, 8, 9, 8, 3};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) //test 0 --> create new linked list
    {
        int *val = malloc(sizeof(int));
        *val = values[i];
        Add(&myLinkedList, val);
    }

    PrintList(&myLinkedList); //test 1 --> print list

    int value = *(int *)myLinkedList.head->value;
    printf("el head de la lista enlazada es: %d\n", value);

    printf(Exists(myLinkedList, &(int){70}) ? "Existe el número 70" : "que va, aqui no hay na"); //test 2 --> check if value exists within the list

    freeList(myLinkedList); //final test --> free linked list from memory 
    return 0;
}
