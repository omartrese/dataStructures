#include <iostream>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <memory>

void mergeSort(int *array, size_t len) {
  if (len <= 1)
    return;
  if (len == 2) {
    if (array[0] > array[1])
      std::swap(array[0], array[1]);
  }

  size_t const mid = len / 2;
  size_t const left_len = mid;
  size_t const right_len = len - mid;

  mergeSort(&array[0], left_len);
  mergeSort(&array[mid], right_len);

  auto const array_clone = std::make_unique<int[]>(len);
  ::memcpy(&array_clone[0], array, len * sizeof(int));

  int const *left = &array_clone[0];
  int const *right = &array_clone[mid];

  size_t i1 = 0, i2 = 0, i = 0;
  for (; i1 < left_len && i2 < right_len; ++i) {
    if (left[i1] < right[i2]) {
      array[i] = left[i1++];
    } else {
      array[i] = right[i2++];
    }
  }

  ::memcpy(&array[i], &left[i1], (left_len - i1) * sizeof(int));
  ::memcpy(&array[i], &right[i2], (right_len - i2) * sizeof(int));
}

static void print_array(int const *items, size_t len) {
  putchar('{');
  if (len > 0) {
    printf("%d", items[0]);
    for (size_t i = 1; i < len; ++i)
      printf(", %d", items[i]);
  }
  puts("}");
}

int main() {
  std::array<int, 10> intgs{};
  for (size_t i = 0; i < intgs.size(); ++i)
    intgs[i] = (int)i;

  srand(time(NULL));

  // shuffle
  for (size_t i = 0; i < intgs.size(); ++i) {
    size_t j = i + rand() % (intgs.size() - i);
    std::swap(intgs[i], intgs[j]);
  }

  // print
  fputs("Before sort: ", stdout);
  print_array(intgs.data(), intgs.size());

  mergeSort(intgs.data(), intgs.size());
  // print
  fputs("After sort: ", stdout);
  print_array(intgs.data(), intgs.size());
}