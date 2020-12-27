#include "../Heap/Heap.h"

template<typename T>
HuffTree<T>::HuffTree(T &val, int freq): root_(new LeafNode<T>(val, freq)) {}

template<typename T>
HuffTree<T>::HuffTree(HuffNode<T> *left, HuffNode<T> *right): root_(new IntlNode<T>(left, right)) {}

template<typename T>
HuffNode<T> *HuffTree<T>::root() const { return root_; }

template<typename T>
int HuffTree<T>::weight() const { return root_->weight(); }

template<typename T>
HuffTree<T> *buildHuff(HuffTree<T> *treeArray, int count, const std::function<bool(T,T)> &comp) {
  auto forest = new Heap<T>(treeArray, count, count, comp);
  HuffTree<char> *temp1, *temp2, *temp3 = nullptr;
  while (forest->length() > 1) {
    temp1 = forest->removeFirst();  // pull first two trees
    temp2 = forest->removeFirst();  // of the list
    temp3 = new HuffTree<T>(temp1, temp2);
    forest->insert(temp3);  // put the new tree back on list
    delete temp1;
    delete temp2;
  }

  return temp3;
}
