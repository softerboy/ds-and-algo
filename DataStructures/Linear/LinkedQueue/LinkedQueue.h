#ifndef __LINKED_QUEUE_H__
#define __LINKED_QUEUE_H__

#include "../Interfaces/Queue.h"

template<typename T>
class LinkedQueue : public Queue<T> {
 private:
  int _count;

 public:
  explicit LinkedQueue();

  void enqueue(const T &item) override;

  T dequeue() override;

  int length() const override;

  void clear() override;
};

#include "LinkedQueue.inl"

#endif // __LINKED_QUEUE_H__
