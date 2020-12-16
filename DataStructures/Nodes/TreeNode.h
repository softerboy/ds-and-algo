#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

/**
 * Node for abstract tree
 * @tparam Key The type of key for record
 * @tparam Record The type of record to be bind to key
 */
template<typename Key, typename Record>
class TreeNode {
 public:
  Key key_;
  Record record_;
  TreeNode<Key, Record> *left_;
  TreeNode<Key, Record> *right_;

 public:
  TreeNode(const Key &key,
           const Record &record,
           TreeNode<Key, Record> *left = nullptr,
           TreeNode<Key, Record> *right = nullptr);
};

#include "TreeNode.inl"

#endif // __TREE_NODE_H__
