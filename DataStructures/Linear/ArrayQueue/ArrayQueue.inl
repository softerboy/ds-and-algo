#include <cassert>

template<typename T>
ArrayQueue<T>::ArrayQueue(int capacity): _count(0), _maxsize(capacity), _items(new T[capacity]) {}

template<typename T>
ArrayQueue<T>::~ArrayQueue() { clear(); }

template<typename T>
void ArrayQueue<T>::enqueue(const T &item) {
  assert(_count <= _maxsize);

  // make a room for new node
  for (int i = _count - 1; i >= 0; --i)
    _items[i] = _items[i - 1];

  _items[0] = item;
  _count++;
}

template<typename T>
T ArrayQueue<T>::dequeue() {
  assert(_count > 0);
  return _items[--_count];
}

template<typename T>
int ArrayQueue<T>::length() const {
  return _count;
}

template<typename T>
void ArrayQueue<T>::clear() {
  delete[] _items;
  _items = nullptr;
  _count = 0;
}
