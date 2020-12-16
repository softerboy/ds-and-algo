#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include "../../Nodes/DoublyLinkNode.h"

/**
 * Doubly linked list implementation for list interface
 * @tparam T - a type of elements being stored in list
 */
template<typename T>
class DoublyLinkedList : public List<T> {
 private:
  int _count;                   // number of current elements in the list
  DoublyLinkNode<T>* _head;   // pointer to head node
  DoublyLinkNode<T>* _tail;     // pointer to tail node

 public:
  explicit DoublyLinkedList();

  ~DoublyLinkedList();

  void clear() override;

  void append(const T &item) override;

  void insert(const T &item, int pos) override;

  T remove(int index) override;

  T get(int index) override;

  int length() const override;
};

#include "DoublyLinkedList.inl"

#endif // __DOUBLY_LINKED_LIST_H__
