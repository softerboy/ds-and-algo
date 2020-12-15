#include "../../Errors/RangeError.h"

template<typename T>
LinkedList<T>::LinkedList() {
  _count = 0;
  _head = _tail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
  clear();
  delete _head;
  _head = nullptr;
}

template<typename T>
void LinkedList<T>::clear() {

  auto curr = _head;
  while (curr != _tail) {
    auto temp = curr->next();
    delete curr;
    curr = temp;
  }

  _head = _tail = nullptr;
  _count = 0;
}

template<typename T>
void LinkedList<T>::append(const T &item) {
  if (_head == nullptr) { // empty list
    _head = new SingleLinkNode<T>(NULL);
    _tail = new SingleLinkNode<T>(item);
    _head->setNext(_tail);
  } else { // non empty list
    _tail->setNext(new SingleLinkNode<T>(item));
    _tail = _tail->next();
  }

  _count++;
}

template<typename T>
void LinkedList<T>::insert(const T &item, int pos) {
  auto curr = _head;

  auto i = 0;
  while (curr) {
    if (i == pos) break;
    ++i;
    curr = curr->next();
  }

  curr->setNext(new SingleLinkNode<T>(item, curr->next()));
  _count++;
}

template<typename T>
T LinkedList<T>::remove(int index) {
  if (_count == 0) throw RangeError(0, "List is empty!");

  auto curr = _head;
  auto i = 0;
  while (curr) {
    if (i == index) break;
    curr = curr->next();
    i++;
  }

  auto temp = curr->next();
  curr->setNext(temp->next());

  auto d = temp->data();
  delete temp;
  _count--;

  return d;
}

template<typename T>
T LinkedList<T>::get(int index) {
  if (_count == 0) throw RangeError(0, "List is empty");

  int i = 0;
  auto curr = _head->next();
  while (curr) {
    if (i == index) break;
    curr = curr->next();
    ++i;
  }

  return curr->data();
}

template<typename T>
int LinkedList<T>::length() const {
  return _count;
}
