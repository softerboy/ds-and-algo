#ifndef __QUEUE_H__
#define __QUEUE_H__

/**
 * ArrayQueue abstract class definition
 * @tparam T - type of element being stored in queue
 */
template<typename T>
class Queue {
 private:
  void operator=(const Queue &) {};          // protect assignment NOLINT(cert-oop54-cpp)
  Queue(const Queue &) = default;             // protect copy constructor

 public:
  /**
   * Default constructor
   */
  explicit Queue() = default;

  /**
   * Base destructor
   */
  virtual ~Queue() = default;

  /**
   * Push back item into queue
   * @param item - an item being enqueued
   */
  virtual void enqueue(const T &item) = 0;

  /**
   * Pop item from queue
   * @return an element in front of in the queue
   */
  virtual T dequeue() = 0;

  /**
   * Current number of elements in the queue
   * @return
   */
  virtual int length() const = 0;

  /**
   * Remove all elements from queue
   * Free memory
   */
   virtual void clear() = 0;
};

#endif // __QUEUE_H__