#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#include "../Interfaces/Stack.h"

/**
 * Array based stack implementation
 * @tparam T - an element type being saved in the stack
 */
template<typename T>
class ArrayStack : public Stack<T> {
 private:
  int _count;     // number of current elements in the stack
  int _maxSize;   // maximum size of stack
  T *_items;      // array for holding stack elements

 public:
  /**
   * Initializes array based stack with given size (capacity)
   * @param size - maximum size of the stack
   */
  explicit ArrayStack(int size = 10);
  ~ArrayStack();

  void push(const T &item) override;

  T pop() override;

  void clear() override;

  int length() const override;
};

#include "ArrayStack.inl"

#endif // __ARRAY_STACK_H__