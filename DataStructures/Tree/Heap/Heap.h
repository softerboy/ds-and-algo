#ifndef __HEAP_H__
#define __HEAP_H__

#include <algorithm>

template<typename T, typename Compare>
class Heap {
 private:
  T *heap_;           // Pointer to the heap array
  int maxsize_;       // Maximum size of the heap
  int n_;             // Number of elements now in the heap

  // Helper function to put element in it's correct position
  void siftdown(int pos) {
    // stop if pos is a leaf
    while (!isLeaf(pos)) {
      // set max to left child
      int max = leftchild(pos);
      int rc = rightchild(pos);
      // if right child max than left child
      if (rc < n_ && Compare::prior(heap_[rc], heap_[max]))
        max = rc; // set max to right child

      // if parent greater than max child sifting is done
      if (Compare::prior(heap_[pos], heap_[max])) return;
      // swap parent and max child
      std::swap(heap_[pos], heap_[max]);
      // move down
      pos = max;
    }
  }

 public:
  /**
   * @param heap Initial state of heap
   * @param n Number of elements in heap
   * @param max Capacity of heap
   */
  Heap(T *heap, int n, int max);

  /**
   * @return The count of elements in the heap
   */
  int length() const;

  /**
   * @param pos Position of element in the heap
   * @return true if element in pos is leaf
   */
  bool isLeaf(int pos) const;

  /**
   * @param pos Position of element in heap
   * @return Left child of element in pos
   */
  int leftchild(int pos) const;

  /**
   * @param pos Position of element in heap
   * @return Right child of element in pos
   */
  int rightchild(int pos) const;

  /**
   * @param pos Position of element in heap
   * @return Parent index of element in pos
   */
  int parent(int pos) const;

  /**
   * Heapify contents of heap
   */
  void buildHeap();

  /**
   * Insert new item into heap
   * @param item Item  should be inserted to heap
   */
  void insert(const T& item);

  /**
   * @return Remove and return first value
   */
  T removeFirst();

  /**
   * Remove element at specific position
   * @param pos
   * @return
   */
  T remove(int pos);

  T get(int pos) const;
};

#include "Heap.inl"

#endif // __HEAP_H__
