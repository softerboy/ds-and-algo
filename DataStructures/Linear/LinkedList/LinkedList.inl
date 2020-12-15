#include <cassert>
#include "../../Errors/RangeError.h"

template<typename T>
LinkedList<T>::LinkedList() {
  _count = 0;
  // sentinel head
  _head = _tail = new SingleLinkNode<T>(NULL);
}

template<typename T>
LinkedList<T>::~LinkedList() {
  clear();
  delete _head;
  _head = nullptr;
}

template<typename T>
void LinkedList<T>::clear() {

  auto iter = _head->_next;
  SingleLinkNode<T> *temp = nullptr;
  while (iter != _tail) {
    temp = iter;
    iter = iter->_next;
    delete temp;
  }

  _tail = _head;
  _count = 0;
}

template<typename T>
void LinkedList<T>::append(const T &item) {
  _tail = _tail->_next = new SingleLinkNode<T>(item);
  _count++;
}

template<typename T>
void LinkedList<T>::insert(const T &item, int pos) {
  assert(pos >=0 && pos < _count);
  auto curr = _head;

  auto i = 0;
  while (i != pos) { ++i, curr = curr->_next; }

  curr->_next = new SingleLinkNode<T>(item, curr->_next);
  _count++;
}

template<typename T>
T LinkedList<T>::remove(int pos) {
  if (_count == 0) throw RangeError(0, "List is empty!");
  assert(pos >=0 && pos < _count);

  auto iter = _head;
  auto i = 0;
  while (pos != i) {
    i++;
    iter = iter->_next;
  }

  auto temp = iter->_next;
  iter->_next = temp->_next;
  if (pos == _count - 1)
    _tail = iter->_next;

  auto d = temp->_data;
  delete temp;
  _count--;

  return d;
}

template<typename T>
T LinkedList<T>::get(int index) {
  if (_count == 0) throw RangeError(0, "List is empty");

  int i = 0;
  auto curr = _head->_next;
  while (index != i) {
    ++i;
    curr = curr->_next;
  }

  return curr->_data;
}

template<typename T>
int LinkedList<T>::length() const {
  return _count;
}
