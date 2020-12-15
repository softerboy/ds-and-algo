#include <cassert>

template<typename T>
RingQueue<T>::RingQueue(int capacity):
    _capacity(capacity + 1), _front(1), _back(0), _items(new T[capacity + 1]) {}

template<typename T>
RingQueue<T>::~RingQueue() { delete[] _items; }

template<typename T>
void RingQueue<T>::enqueue(const T &item) {
  assert((_back + 2) % _capacity != _front);
  _back = (_back + 1) % _capacity;
  _items[_back] = item;
}

template<typename T>
T RingQueue<T>::dequeue() {
  assert(length() != 0);

  auto result = _items[_front];
  _front = (_front + 1) % _capacity;
  return result;
}

template<typename T>
int RingQueue<T>::length() const {
  return ((_back + _capacity) - _front + 1) % _capacity;
}

template<typename T>
void RingQueue<T>::clear() {
  _back = 0, _front = 1;
}
