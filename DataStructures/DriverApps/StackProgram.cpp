#include <iostream>

#include "../Linear/ArrayStack/ArrayStack.h"
#include "../Linear/LinkedStack/LinkedStack.h"

void testStack(Stack<int> *stack) {
    for (int i = 0; i < 10; ++i)
        stack->push(i);

    auto len = stack->length();
    for (int i = 0; i < len; ++i)
        std::cout << stack->pop() << " ";
}

int main() {
    auto astack = new ArrayStack<int>();
    auto lstack = new LinkedStack<int>();

    std::cout << "Testing array stack\n";
    testStack(astack);
    std::cout << "\nTesting linked stack\n";
    testStack(lstack);

    delete astack;
    delete lstack;
    return 0;
}