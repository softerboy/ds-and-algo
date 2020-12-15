#include <iostream>

#include "../Linear/RingQueue/RingQueue.h"
#include "../Linear/ArrayQueue/ArrayQueue.h"
#include "../Linear/LinkedQueue/LinkedQueue.h"

void testQueue(Queue<int> *queue) {
  for (int i = 0; i < 10; ++i) queue->enqueue(i);

  auto len = queue->length();
  for (int i = 0; i < len; ++i)
    std::cout << queue->dequeue() << " ";
}

int main() {
  auto aqueue = new ArrayQueue<int>();
  auto lqueue = new LinkedQueue<int>();
  auto rqueue = new RingQueue<int>();

  std::cout << "Testing array queue\n";
  testQueue(aqueue);

  std::cout << "\nTesting linked queue\n";
  testQueue(lqueue);

  std::cout << "\nTesting ring queue\n";
  testQueue(rqueue);

  delete aqueue;
  delete lqueue;
  delete rqueue;

  return 0;
}