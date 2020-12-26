#include <iostream>

#include "../Utils.h"
#include "../Sort.h"

int main() {
  int arr[] = {23, 4, 56, -1, 3, -5, 94};

  std::cout << "Array before sorting:" << std::endl;
  printArray(arr, 7);

  insertionSort<int>(arr, 7, [](const int &a, const int &b) {
    return a < b;
  });
  std::cout << "\nArray after sorting:" << std::endl;
  printArray(arr, 7);

  return 0;
}