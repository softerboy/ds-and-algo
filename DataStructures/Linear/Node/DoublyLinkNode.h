#ifndef __DOUBLY_LINK_NODE_H__
#define __DOUBLY_LINK_NODE_H__

template<typename T>
class DoublyLinkNode {
 public:
  DoublyLinkNode(const T &data, DoublyLinkNode<T> *next = nullptr, DoublyLinkNode<T> *prev = nullptr);

  T _data;
  DoublyLinkNode<T> *_next;
  DoublyLinkNode<T> *_prev;
};

#include "DoublyLinkNode.inl"

#endif // __DOUBLY_LINK_NODE_H__