#include <cassert>

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList():
    _count(0) {
  // make a head and tail sentinels
  _head = new DoublyLinkNode<T>(0);
  _tail = new DoublyLinkNode<T>(0);
  _head->_next = _tail;
  _tail->_prev = _head;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
  auto iter = _head->_next;
  while (iter != _tail) {
    auto temp = iter;
    iter = iter->_next;
    delete temp;
  }

  _count = 0;
}

template<typename T>
void DoublyLinkedList<T>::append(const T &item) {
  _tail->_prev = _tail->_prev->_next = new DoublyLinkNode<T>(item, _tail, _tail->_prev);
  _count++;
}

template<typename T>
void DoublyLinkedList<T>::insert(const T &item, int pos) {
  assert(pos >= 0 && pos <= _count);

  auto i = 0;
  auto iter = _head->_next;
  while (i != pos) {
    iter = iter->_next;
    i++;
  }

  iter->_prev = iter->_prev->_next = new DoublyLinkNode<T>(item, iter, iter->_prev);

  _count++;
}

template<typename T>
T DoublyLinkedList<T>::remove(int pos) {
  assert(_count != 0);
  assert(pos >= 0 && pos < _count);

  auto i = 0;
  auto iter = _head->_next;
  while (pos != i) {
    iter = iter->_next;
    ++i;
  }

  iter->_prev->_next = iter->_next;
  iter->_next->_prev = iter->_prev;

  auto data = iter->_data;
  delete iter;

  _count--;
  return data;
}

template<typename T>
T DoublyLinkedList<T>::get(int pos) {
  assert(pos >= 0 && pos < _count);

  auto i = 0;
  auto iter = _head->_next;
  while (i != pos) {
    ++i;
    iter = iter->_next;
  }

  return iter->_data;
}

template<typename T>
int DoublyLinkedList<T>::length() const {
  return _count;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  clear();
  // free up sentinels
  delete _head;
  delete _tail;
}
