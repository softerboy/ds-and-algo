#include "../DataStructures/Tree/Heap/Heap.h"

template<typename T>
void heapSort(T array[], int n, const Comparator<T> &comp) {
  Heap<T> h(array, n, n, comp); // build the heap
  for (int i = 0; i < n; ++i)
    h.removeFirst();
}