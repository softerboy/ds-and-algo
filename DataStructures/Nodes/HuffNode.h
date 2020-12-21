#ifndef __HUFF_NODE_H__
#define __HUFF_NODE_H__

/**
 * Huffman tree node abstract base class
 */
template<typename T>
class HuffNode {
  virtual ~HuffNode() = default;  // Base destructor
  virtual int weight() = 0;       // Return frequency
  virtual bool isLeaf() = 0;      // Determine type
};

template <typename T>
class LeafNode : public HuffNode<T> {
 private:
  T it_;    // value
  int wgt_; // weight

 public:
  LeafNode(const T& val, int freq);
 private:
  int weight() override;
  bool isLeaf() override;
};

template <typename T>
class IntlNode : public HuffNode<T> {
 private:
  HuffNode<T>* lc_;   // left child
  HuffNode<T>* rc_;   // right child
  int wgt_;           // subtree weight

 public:
  IntlNode(HuffNode<T>* l, HuffNode<T>* r);
 private:
  int weight() override;
  bool isLeaf() override;

  HuffNode<T>* left() const;
  void setLeft(HuffNode<T>* l);

  HuffNode<T>* right() const;
  void setRight(HuffNode<T>* r);
};

#include "HuffNode.inl"

#endif // __HUFF_NODE_H__
