#include "RangeError.h"

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
        auto temp = curr->_next;
        delete curr;
        curr = temp;
    }

    _head = _tail = nullptr;
    _count = 0;
}

template<typename T>
void LinkedList<T>::append(const T &item) {
    if (_head == nullptr) { // empty list
        _head = new Node<T>(NULL);
        _head->_next = _tail = new Node<T>(item);
    } else { // non empty list
        _tail = _tail->_next = new Node<T>(item);
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
        curr = curr->_next;
    }

    curr->_next = new Node<T>(item, curr->_next);
    _count++;
}

template<typename T>
T LinkedList<T>::remove(int index) {
    if (_count == 0) throw RangeError(0, "List is empty!");

    auto curr = _head;
    auto i = 0;
    while (curr) {
        if (i == index) break;
        curr = curr->_next;
        i++;
    }

    auto temp = curr->_next;
    curr->_next = temp->_next;

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
    while (curr) {
        if (i == index) break;
        curr = curr->_next;
        ++i;
    }

    return curr->_data;
}

template<typename T>
int LinkedList<T>::length() const {
    return _count;
}
