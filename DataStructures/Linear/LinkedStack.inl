namespace {
template<typename T>
Node<T>::Node(const T &data, Node<T> *next): _data(data), _next(next) {}

template<typename T>
T Node<T>::data() const {
    return _data;
}

template<typename T>
Node<T> *Node<T>::next() const {
    return _next;
}
}

template<typename T>
LinkedStack<T>::LinkedStack(): _count(0), _head(nullptr) {}

template<typename T>
LinkedStack<T>::~LinkedStack() { clear(); }

template<typename T>
T LinkedStack<T>::pop() {
    assert(_count > 0);

    auto temp = _head;
    _head = _head->next();
    _count--;
    return temp->data();
}

template<typename T>
void LinkedStack<T>::push(const T &item) {
    if (_head == NULL) {
        _head = new Node<T>(item);
    } else {
        _head = new Node<T>(item, _head);
    }
    _count++;
}

template<typename T>
void LinkedStack<T>::clear() {
    auto iter = _head;
    while (iter) {
        auto temp = iter;
        iter = iter->next();
        delete temp;
    }
    _count = 0;
}

template<typename T>
int LinkedStack<T>::length() const {
    return _count;
}
