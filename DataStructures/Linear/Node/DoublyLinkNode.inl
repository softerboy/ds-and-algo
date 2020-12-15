template<typename T>
DoublyLinkNode<T>::DoublyLinkNode(const T &data, DoublyLinkNode<T> *next, DoublyLinkNode<T> *prev)
    : _data(data), _next(next), _prev(prev) {}
