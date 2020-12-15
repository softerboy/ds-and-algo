#include <iostream>

#include "../Linear/Interfaces/Queue.h"
#include "../Linear/ArrayQueue/ArrayQueue.h"
#include "../Linear/LinkedQueue/LinkedQueue.h"

void testQueue(Queue<int>* queue) {
  for (int i = 0; i < 10; ++i) queue->enqueue(i);

  auto len = queue->length();
  for (int i = 0; i < len; ++i)
    std::cout << queue->dequeue() << " ";
}

int main() {
  auto aqueue = new ArrayQueue<int>();
  auto lqueue = new LinkedQueue<int>();

  std::cout << "Testing array queue\n";
  testQueue(aqueue);

  std::cout << "\nTesting linked queue\n";
  testQueue(lqueue);

  delete aqueue;
  return 0;
}