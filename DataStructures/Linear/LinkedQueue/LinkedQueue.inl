#include <cassert>

template<typename T>
LinkedQueue<T>::LinkedQueue(): _count(0), _front(nullptr), _back(nullptr) {}

template<typename T>
void LinkedQueue<T>::enqueue(const T &item) {
  if (_front == nullptr) {
    _back = _front = new SingleLinkNode<T>(item);
  } else {
    _back->setNext(new SingleLinkNode<T>(item));
    _back = _back->next();
  }
  _count++;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
  assert(_count > 0);

  // store removed data first
  auto data = _front->data();
  // link to deletable pointer
  auto temp = _front;
  // set front to front's next
  _front = _front->next();

  // free up memeory
  delete temp;

  // increase size
  _count--;
  return data;
}

template<typename T>
int LinkedQueue<T>::length() const {
  return _count;
}

template<typename T>
void LinkedQueue<T>::clear() {
  auto iter = _front;
  while (iter) {
    auto temp = iter;
    iter = iter->next();
    delete temp;
  }
  _back = _front;
  _count = 0;
}
