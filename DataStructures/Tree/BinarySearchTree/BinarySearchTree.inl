
#include "BinarySearchTree.h"

template<typename Key, typename Record>
BinarySearchTree<Key, Record>::BinarySearchTree() : count_{0}, root_{nullptr} {}

template<typename Key, typename Record>
BinarySearchTree<Key, Record>::~BinarySearchTree() { clear(); }

template<typename Key, typename Record>
void BinarySearchTree<Key, Record>::clear() {
  clear_(root_);
  count_ = 0;
}

template<typename Key, typename Record>
void BinarySearchTree<Key, Record>::insert(const Key &key, const Record &record) {
  root_ = insert_(root_, key, record);
}

template<typename Key, typename Record>
Record *BinarySearchTree<Key, Record>::remove(const Key &key) {
  auto found = find(key);
  if (found != nullptr) {
    remove_(root_, key);
    count_--;
  }
  return found;
}

template<typename Key, typename Record>
Record *BinarySearchTree<Key, Record>::removeAny() {
  // empty tree
  if (root_ != nullptr) {
    auto oldRoot = new TreeNode<Key, Record>(root_->key_, root_->record_);
    remove_(root_, root_->key_);
    count_--;
    return &(oldRoot->record_);
  }

  return nullptr;
}

template<typename Key, typename Record>
Record *BinarySearchTree<Key, Record>::find(const Key &key) {
  auto found = find_(root_, key);
  if (found == nullptr) return nullptr;
  return new Record(found->record_);
}

template<typename Key, typename Record>
int BinarySearchTree<Key, Record>::size() {
  return count_;
}

template<typename Key, typename Record>
TreeNode<Key, Record> *BinarySearchTree<Key, Record>::insert_(
    TreeNode<Key, Record> *node,
    const Key &key,
    const Record &record
) {
  if (node == nullptr) {
    // empty tree, crate new root
    node = new TreeNode<Key, Record>(key, record);
  } else if (key < node->key_) {
    // key less than node's key
    // insert to left subtree
    node->left_ = insert_(node->left_, key, record);
  } else {
    // otherwise, insert to right subtree
    node->right_ = insert_(node->right_, key, record);
  }
  count_++;
  return node;
}

template<typename Key, typename Record>
void BinarySearchTree<Key, Record>::forEach(const std::function<void(const Key &, const Record &)> &callback) {
  forEach_(root_, callback);
}

template<typename Key, typename Record>
void BinarySearchTree<Key, Record>::forEach_(
    TreeNode<Key, Record> *node,
    const std::function<void(const Key &, const Record &)> &callback
) {
  // empty tree
  if (node == nullptr) return;
  forEach_(node->left_, callback);
  callback(node->key_, node->record_);
  forEach_(node->right_, callback);
}

template<typename Key, typename Record>
TreeNode<Key, Record> *BinarySearchTree<Key, Record>::find_(TreeNode<Key, Record> *node, const Key &key) {
  // empty tree
  if (node == nullptr) return node;

  if (key < node->key_) {
    // search in left subtree
    return find_(node->left_, key);
  } else if (key > node->key_) {
    // search in right subtree
    return find_(node->right_, key);
  }

  // found
  return node;
}

template<typename Key, typename Record>
TreeNode<Key, Record> *BinarySearchTree<Key, Record>::remove_(TreeNode<Key, Record> *node, const Key &key) {
  // empty tree
  if (node == nullptr) return nullptr;

  if (key < node->key_) {
    // remove from left subtree
    node->left_ = remove_(node->left_, key);
  } else if (key > node->key_) {
    // remove from right subtree
    node->right_ = remove_(node->right_, key);
  } else { // found
    // leaf node
    if (node->right_ == nullptr && node->left_ == nullptr) {
      // simply delete it
      delete node;
      node = nullptr;
    } else if (node->left_ == nullptr) {
      // only a right child
      auto temp = node;
      node = node->right_;
      delete temp;
    } else if (node->right_ == nullptr) {
      // only a left child
      auto temp = node;
      node = node->left_;
      delete temp;
    } else {
      // internal node with two children
      auto minNode = min_(node->right_);
      node->key_ = minNode->key_;
      node->record_ = minNode->record_;
      node->right_ = remove_(node->right_, minNode->key_);
    }
  }

  return node;
}

template<typename Key, typename Record>
TreeNode<Key, Record> *BinarySearchTree<Key, Record>::min_(TreeNode<Key, Record> *node) {
  if (node->left_ == nullptr) return node;
  return min_(node->left_);
}

template<typename Key, typename Record>
void BinarySearchTree<Key, Record>::clear_(TreeNode<Key, Record> *node) {
  if (node == nullptr) return;
  clear_(node->left_);
  clear_(node->right_);
  delete node;
}
