#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#include <cassert>
#include <cstdlib>

#include "../Interfaces/Stack.h"
#include "../Node/SingleLinkNode.h"

template<typename T>
class LinkedStack : public Stack<T> {
 private:
  int _count;
  SingleLinkNode<T> *_head;

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