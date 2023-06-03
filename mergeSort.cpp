#include<iostream>
#include<array>

void merge(int arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left; 
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* array, int begin, int end)
{
  if(begin < end)
  {
    int mid = begin + (end - begin) / 2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);

    merge(array, begin, mid, end);
  }
}

static void printArray(int* arr, size_t length)
{
  for(size_t i = 0; i < length; i++)
  {
    std::cout << arr[i] << " ";
  }
}

int main() {
  srand((unsigned) time(NULL));

  int arr[8];
  size_t arrLength = sizeof(arr) / sizeof(arr[0]);
  std::cout << arrLength << std::endl;
  
  // arr = randomNums(arrLength, arr);
  for(size_t i = 0; i < arrLength; i++)
  {
    arr[i] = std::rand() % 16;
  }

  printArray(arr, arrLength);

  mergeSort(arr, 0, arrLength - 1);

  std::cout << std::endl;

  printArray(arr, arrLength);
  return 0;
}