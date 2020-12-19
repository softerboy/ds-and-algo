#include <iostream>

#include "../Tree/Heap/Heap.h"

template<typename T>
class MaxBy {
 public:
  static bool prior(T a, T b) { return a > b; }
};

template<typename T, typename Comparator>
bool testHeap(Heap<T, Comparator> *heap) {
  auto len = heap->length();
  for (int i = len - 1; i >= 0; --i) {
    auto child = heap->get(i);
    auto parent = heap->get(heap->parent(i));
    if (Comparator::prior(child, parent))
      return false;
  }

  return true;
}

int main() {
  int arr[] = {1, 3, 5, 4, 17, 13, 10, 9, 8, 15, 6};
  auto heap = new Heap<int, MaxBy<int>>(arr, 11, 11);

  auto len = heap->length();
  for (int i = 0; i < len - 1; ++i)
    std::cout << heap->get(i) << " ";

  assert(testHeap(heap));

  for (int i = 0; i < len - 1; ++i) {
    heap->removeFirst();
    assert(testHeap(heap));
  }

  len = heap->length() - 1;
  for (int i = 0; i < len - 1; ++i)
    std::cout << heap->get(i) << " ";
  delete heap;
  return 0;
}