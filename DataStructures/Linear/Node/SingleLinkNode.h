#ifndef __SINGLE_LINK_NODE_H__
#define __SINGLE_LINK_NODE_H__

template<typename T>
class SingleLinkNode {
 private:
  T _data;
  SingleLinkNode<T> *_next;

 public:
  SingleLinkNode(const T &data, SingleLinkNode<T> *next = nullptr);

  T data() const;
  SingleLinkNode<T> *next() const;
  void setNext(SingleLinkNode<T>* next);
};

#include "SingleLinkNode.inl"

#endif // __SINGLE_LINK_NODE_H__