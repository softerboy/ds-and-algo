#include <cassert>
#include "Heap.h"

template<typename T, typename Compare>
Heap<T, Compare>::Heap(T *heap, int n, int max): heap_(heap), n_(n), maxsize_(max) { buildHeap(); }

template<typename T, typename Compare>
int Heap<T, Compare>::length() const {
  return n_;
}

template<typename T, typename Compare>
bool Heap<T, Compare>::isLeaf(int pos) const {
  return pos >= n_ / 2 && pos < n_;
}

template<typename T, typename Compare>
int Heap<T, Compare>::leftchild(int pos) const {
  return 2 * pos + 1;
}

template<typename T, typename Compare>
int Heap<T, Compare>::rightchild(int pos) const {
  return 2 * pos + 2;
}

template<typename T, typename Compare>
int Heap<T, Compare>::parent(int pos) const {
  return (pos - 1) / 2;
}

template<typename T, typename Compare>
void Heap<T, Compare>::buildHeap() {
  for (int i = n_ / 2 - 1; i >= 0; --i) siftdown(i);
}

template<typename T, typename Compare>
void Heap<T, Compare>::insert(const T &item) {
  assert(n_ < maxsize_); // heap is full

  int curr = n_++;
  heap_[curr] = n_;

  // now sift until curr's parents > curr
  while (curr != 0 && Compare::prior(heap_[curr], heap_[parent(curr)])) {
    std::swap(heap_[curr], heap_[parent(curr)]);
    curr = parent(curr);
  }
}

template<typename T, typename Compare>
T Heap<T, Compare>::removeFirst() {
  assert(n_ > 0); // empty heap
  std::swap(heap_[0], heap_[--n_]);   // swap first with last value
  if (n_ != 0) siftdown(0);       // sift down new root
  return heap_[n_];  // return deleted value
}

template<typename T, typename Compare>
T Heap<T, Compare>::remove(int pos) {
  assert(pos >= 0 && pos < n_); // Bad position

  if (pos == n_ - 1) n_--; // last element, no work to do
  else {
    std::swap(heap_[pos], heap_[--n_]); // swap with last value
    while (pos != 0 && Compare::prior(heap_[pos], heap_[parent(pos)])) {
      std::swap(heap_[pos], heap_[parent(pos)]);  // push up large key
      pos = parent(pos);
    }

    if (n_ != 0) siftdown(pos); // push down small key
  }

  return heap_[n_];
}

template<typename T, typename Compare>
T Heap<T, Compare>::get(int pos) const {
  assert(pos >= 0 && pos < n_);
  return heap_[pos];
}

