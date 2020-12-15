#include <climits>
#include <algorithm>

#include "RangeError.h"

template<typename T>
ArrayList<T>::ArrayList(int size) {
  if (size < 0) throw RangeError(size, "Initial size must be positive integer");
  if (size > INT_MAX) throw RangeError(size, "Initial size must be less than INT_MAX");

  _items = new T[size];
  _count = 0;
  _size = size;
}

template<typename T>
void ArrayList<T>::clear() {
  delete[] _items;

  _items = new T[_size];
  _count = 0;
}

template<typename T>
void ArrayList<T>::append(const T &item) {
  if (_count == _size)
    _doubleCapacity();

  _items[_count++] = item;
}

template<typename T>
void ArrayList<T>::insert(const T &item, int pos) {
  if (_count == _size)
    _doubleCapacity();

  // shift all elements after pos to right
  // i.e. make a room for new element
  for (int i = _count - 1; i >= pos; --i)
    _items[i + 1] = _items[i];

  _items[pos] = item;
  _count++;
}

template<typename T>
T ArrayList<T>::remove(int pos) {
  auto item = _items[pos];

  for (int i = pos; i < _count; ++i)
    _items[i] = _items[i + 1];

  _count--;
  return item;
}

template<typename T>
T ArrayList<T>::get(int index) {
  return _items[index];
}

template<typename T>
ArrayList<T>::~ArrayList() { clear(); }

template<typename T>
int ArrayList<T>::length() const {
  return _count;
}

template<typename T>
void ArrayList<T>::_doubleCapacity() {
  _size *= 2;
  auto temp = new T[_size];
  std::copy(_items, _items + _count, temp);
  _items = temp;
}
