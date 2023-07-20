#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int* array, size_t arrLength)
{
    bool swapped = true;

    do
    {
        swapped = false;
        for(int i = 0; i < arrLength; i++)
        {
            if(array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                swapped = true;
                for(int j = 0; j < arrLength; j++) {std::cout << array[j] << " ";}
                std::cout << std::endl;
            }
        }
    } while(swapped);
}

int main() 
{   
    int unorderedArr[10];

    size_t length = sizeof(unorderedArr) / sizeof(unorderedArr[0]);

    for(size_t i = 0; i < length; i++)
    {
        unorderedArr[i] = std::rand() % 20;
    }

    bubbleSort(unorderedArr, length);

    std::cout << length;

    return 0;
}