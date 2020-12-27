#ifndef __HUFF_TREE_H__
#define __HUFF_TREE_H__

#include <functional>

#include "../../Nodes/HuffNode.h"

template<typename T>
class HuffTree {
 private:
  HuffNode<T> *root_;

 public:
  // leaf node constructor
  HuffTree(T &val, int freq);

  // internal node constructor
  HuffTree(HuffNode<T> *left, HuffNode<T> *right);

  // destructor;
  ~HuffTree() = default;

  HuffNode<T> *root() const;

  int weight() const;
};

template<typename T>
HuffTree<T> *buildHuff(HuffTree<T> *treeArray, int count, const std::function<bool(T,T)> &comp = std::less<T>());

#include "HuffTree.inl"

#endif // __HUFF_TREE_H__
