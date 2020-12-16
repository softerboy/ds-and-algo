#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "../../Interfaces/List.h"
#include "../../Nodes/SingleLinkNode.h"

template<typename T>
class LinkedList : public List<T> {
 private:
  int _count;
  SingleLinkNode<T> *_head;
  SingleLinkNode<T> *_tail;

 public:
  explicit LinkedList();
  ~LinkedList();

  void clear() override;

  void append(const T &item) override;

  void insert(const T &item, int pos) override;

  T remove(int pos) override;

  T get(int index) override;

  int length() const override;
};

#include "LinkedList.inl"

#endif // __LINKED_LIST_H__