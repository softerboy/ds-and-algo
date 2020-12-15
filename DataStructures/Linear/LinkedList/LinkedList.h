#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "../Interfaces/List.h"

namespace {
template<typename T>
class Node {
 public:
  T _data;
  Node<T> *_next;

 public:
  explicit Node(T data, Node<T> *next = nullptr) : _data(data), _next(next) {}
};
}

template<typename T>
class LinkedList : public List<T> {
 private:
  int _count;
  Node<T> *_head;
  Node<T> *_tail;

 public:
  explicit LinkedList();
  ~LinkedList();

  void clear() override;

  void append(const T &item) override;

  void insert(const T &item, int pos) override;

  T remove(int index) override;

  T get(int index) override;

  int length() const override;
};

#include "LinkedList.inl"

#endif // __LINKED_LIST_H__