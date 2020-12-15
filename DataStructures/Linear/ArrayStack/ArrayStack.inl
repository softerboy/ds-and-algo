#include <cassert>

template<typename T>
ArrayStack<T>::ArrayStack(int size): _maxSize(size), _count(0), _items(new T[size]) {}

template<typename T>
ArrayStack<T>::~ArrayStack() { clear(); }

template<typename T>
void ArrayStack<T>::push(const T &item) {
  assert(_count != _maxSize);
  _items[_count++] = item;
}

template<typename T>
T ArrayStack<T>::pop() {
  assert(_count > 0);
  return _items[--_count];
}

template<typename T>
void ArrayStack<T>::clear() {
  _count = 0;
  delete[] _items;
  _items = nullptr;
}

template<typename T>
int ArrayStack<T>::length() const {
  return _count;
}
