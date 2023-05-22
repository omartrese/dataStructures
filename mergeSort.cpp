#include <iostream>
#include <stdlib.h>
#include <cstdlib>

int main() {
  srand((unsigned) time(NULL));

  int arrSz = 6;
  int array[arrSz];
  for (int i = 0; i < arrSz; i++)
  {
    int random = rand() % 10;
    array[i] = random;
  }
  for (int i = 0; i < arrSz; i++)
  {
    std::cout << array[i] << std::endl;
  }
  
  return 0;
}