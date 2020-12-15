#ifndef __RING_QUEUE_H__
#define __RING_QUEUE_H__

#include "../Interfaces/Queue.h"

/**
 * Array based implementation of ring queue
 * Note: enqueue and dequeue operations takes O(1) time
 * @tparam T - an type of elements stored in queue
 */
template<typename T>
class RingQueue : public Queue<T> {
 private:
  T *_items;
  int _back;
  int _front;
  int _capacity;

 public:
  explicit RingQueue(int capacity = 10);

  ~RingQueue();

  void enqueue(const T &item) override;

  T dequeue() override;
  int length() const override;
  void clear() override;
};

#include "RingQueue.inl"

#endif // __RING_QUEUE_H__