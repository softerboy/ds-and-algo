#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

#include "../Interfaces/Queue.h"

template<typename T>
class ArrayQueue : public Queue<T> {
 private:
  T *_items;
  int _count;
  int _maxsize;

 public:
  explicit ArrayQueue(int capacity = 10);

  ~ArrayQueue();

  void enqueue(const T &item) override;

  T dequeue() override;

  int length() const override;

  void clear() override;

};

#include "ArrayQueue.inl"

#endif // __ARRAY_QUEUE_H__
