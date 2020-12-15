template<typename T>
SingleLinkNode<T>::SingleLinkNode(const T &data, SingleLinkNode<T> *next)
    : _data(data), _next(next) {}

template<typename T>
T SingleLinkNode<T>::data() const {
  return _data;
}

template<typename T>
SingleLinkNode<T> *SingleLinkNode<T>::next() const {
  return _next;
}

template<typename T>
void SingleLinkNode<T>::setNext(SingleLinkNode<T> *next) {
  _next = next;
}
