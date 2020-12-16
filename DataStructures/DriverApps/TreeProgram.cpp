#include <iostream>

#include "../Tree/BinarySearchTree/BinarySearchTree.h"

int main() {
  auto tree = new BinarySearchTree<int, int>();
  auto items = {12, 4, 55, 2, 45, 65, 22, -3, -4, 27};

  for (auto i : items) tree->insert(i, i);

  std::cout << "Removed root " << *(tree->removeAny()) << std::endl;
  std::cout << "Removed key with " << *(tree->remove(-4)) << std::endl;
  std::cout << "Key with 22: " << *(tree->find(22)) << std::endl;

  tree->forEach([](const int &key, const int &record) {
    std::cout << key << " -> " << record << std::endl;
  });


  return 0;
}
