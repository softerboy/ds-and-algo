#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <functional>

#include "../../Nodes/TreeNode.h"
#include "../../Interfaces/Dictionary.h"

/**
 * Binary tree implementation
 * @tparam Key
 * @tparam Record
 */
template<typename Key, typename Record>
class BinarySearchTree : public Dictionary<Key, Record> {
 private:
  int count_;                         // Current number of nodes in the tree
  TreeNode<Key, Record> *root_;       // Tree's root node

  // insert helper
  TreeNode<Key, Record> *insert_(TreeNode<Key, Record> *node, const Key &key, const Record &record);

  // forEach helper
  void forEach_(TreeNode<Key, Record> *node, const std::function<void(const Key &, const Record &)> &callback);

  // find helper
  TreeNode<Key, Record> *find_(TreeNode<Key, Record> *node, const Key &key);

  // remove helper
  TreeNode<Key, Record> *remove_(TreeNode<Key, Record> *node, const Key &key);

  // min helper, returns records min key
  TreeNode<Key, Record> *min_(TreeNode<Key, Record> *node);

  void clear_(TreeNode<Key, Record> *node);

 public:
  BinarySearchTree();   // Constructor

  ~BinarySearchTree();  // Destructor

  void clear() override;

  void insert(const Key &key, const Record &record) override;

  Record *remove(const Key &key) override;
  /**
   * Remove and return the root node from the dictionary.
   * @return Return: The record removed, null if tree is empty.
   */
  Record *removeAny() override;

  Record *find(const Key &key) override;

  int size() override;

  void forEach(const std::function<void(const Key &key, const Record &record)> &callback);
};

#include "BinarySearchTree.inl"

#endif // __BINARY_SEARCH_TREE_H__