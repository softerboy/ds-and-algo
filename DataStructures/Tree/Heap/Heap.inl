#include <cassert>
#include "Heap.h"

template<typename T>
Heap<T>::Heap(T *heap, int n, int max, const Compare<T> &compare)
    : heap_(heap), n_(n), maxsize_(max), comp_(compare) { buildHeap(); }

template<typename T>
int Heap<T>::length() const {
  return n_;
}

template<typename T>
bool Heap<T>::isLeaf(int pos) const {
  return pos >= n_ / 2 && pos < n_;
}

template<typename T>
int Heap<T>::leftchild(int pos) const {
  return 2 * pos + 1;
}

template<typename T>
int Heap<T>::rightchild(int pos) const {
  return 2 * pos + 2;
}

template<typename T>
int Heap<T>::parent(int pos) const {
  return (pos - 1) / 2;
}

template<typename T>
void Heap<T>::buildHeap() {
  for (int i = n_ / 2 - 1; i >= 0; --i) siftdown(i);
}

template<typename T>
void Heap<T>::insert(const T &item) {
  assert(n_ < maxsize_); // heap is full

  int curr = n_++;
  heap_[curr] = n_;

  // now sift until curr's parents > curr
  while (curr != 0 && comp_(heap_[curr], heap_[parent(curr)])) {
    std::swap(heap_[curr], heap_[parent(curr)]);
    curr = parent(curr);
  }
}

template<typename T>
T Heap<T>::removeFirst() {
  assert(n_ > 0); // empty heap
  std::swap(heap_[0], heap_[--n_]);   // swap first with last value
  if (n_ != 0) siftdown(0);       // sift down new root
  return heap_[n_];  // return deleted value
}

template<typename T>
T Heap<T>::remove(int pos) {
  assert(pos >= 0 && pos < n_); // Bad position

  if (pos == n_ - 1) n_--; // last element, no work to do
  else {
    std::swap(heap_[pos], heap_[--n_]); // swap with last value
    while (pos != 0 && comp_(heap_[pos], heap_[parent(pos)])) {
      std::swap(heap_[pos], heap_[parent(pos)]);  // push up large key
      pos = parent(pos);
    }

    if (n_ != 0) siftdown(pos); // push down small key
  }

  return heap_[n_];
}

template<typename T>
T Heap<T>::get(int pos) const {
  assert(pos >= 0 && pos < n_);
  return heap_[pos];
}

