#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#include <cassert>
#include <cstdlib>

#include "../Interfaces/Stack.h"

namespace {
template<typename T>
class Node {
 private:
  T _data;
  Node<T> *_next;

 public:
  explicit Node(const T &data, Node<T> *next = nullptr);

  T data() const;

  Node<T> *next() const;
};
}

template<typename T>
class LinkedStack : public Stack<T> {
 private:
  int _count;
  Node<T> *_head;

 public:
  explicit LinkedStack();
  ~LinkedStack();

  T pop() override;

  void push(const T &item) override;

  void clear() override;

  int length() const override;
};

#include "LinkedStack.inl"

#endif // __LINKED_STACK_H__