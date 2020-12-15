#ifndef __SINGLE_LINK_NODE_H__
#define __SINGLE_LINK_NODE_H__

template<typename T>
class SingleLinkNode {
 public:
  T _data;
  SingleLinkNode<T> *_next;

  SingleLinkNode(const T &data, SingleLinkNode<T> *next = nullptr);
};

#include "SingleLinkNode.inl"

#endif // __SINGLE_LINK_NODE_H__