
#include "HuffNode.h"

template<typename T>
LeafNode<T>::LeafNode(const T &val, int freq): it_(val), wgt_(freq) {}

template<typename T>
int LeafNode<T>::weight() { return wgt_; }

template<typename T>
bool LeafNode<T>::isLeaf() { return true; }

template<typename T>
IntlNode<T>::IntlNode(HuffNode<T> *l, HuffNode<T> *r) : lc_(l), rc_(r), wgt_(l->weight() + r->weight()) {}

template<typename T>
int IntlNode<T>::weight() { return wgt_; }

template<typename T>
bool IntlNode<T>::isLeaf() { return false; }

template<typename T>
HuffNode<T> *IntlNode<T>::left() const { return lc_; }

template<typename T>
void IntlNode<T>::setLeft(HuffNode<T> *l) { lc_ = l; }

template<typename T>
HuffNode<T> *IntlNode<T>::right() const { return rc_; }

template<typename T>
void IntlNode<T>::setRight(HuffNode<T> *r) { rc_ = r; }


