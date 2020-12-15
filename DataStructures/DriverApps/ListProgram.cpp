#include <iostream>

#include "../Linear/ArrayList/ArrayList.h"
#include "../Linear/LinkedList/LinkedList.h"

#define LOOP_COUNT 15

template<typename T>
void testList(List<T> *list) {
  try {
    for (int i = 0; i < LOOP_COUNT; i++) list->append(i);

    list->insert(12, 3);
    list->insert(10, 3);

    for (int j = 0; j < list->length(); ++j)
      std::cout << list->get(j) << "  ";

    list->remove(3);
    list->remove(0);
    list->remove(list->length() - 1);

    std::cout << std::endl;
    for (int j = 0; j < list->length(); ++j)
      std::cout << list->get(j) << "  ";

  } catch (const RangeError &err) {
    std::cout << err.what() << std::endl;
  }
}

int main() {
  auto alist = new ArrayList<int>();
  auto llist = new LinkedList<int>();

  std::cout << "Testing array list" << std::endl;
  testList(alist);

  std::cout << "\nTesting linked list" << std::endl;
  testList(llist);

  return 0;
}