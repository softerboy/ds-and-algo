add_executable(
        ListProgram
        ../Errors/RangeError.h
        ../Errors/RangeError.cpp
        ../Interfaces/List.h
        ../Nodes/SingleLinkNode.h
        ../Linear/ArrayList/ArrayList.h
        ../Linear/LinkedList/LinkedList.h
        ../Linear/DoublyLinkedList/DoublyLinkedList.h
        ListProgram.cpp
)

add_executable(
        StackProgram
        ../Interfaces/Stack.h
        ../Nodes/SingleLinkNode.h
        ../Linear/ArrayStack/ArrayStack.h
        ../Linear/LinkedStack/LinkedStack.h
        StackProgram.cpp
)

add_executable(
        QueueProgram
        ../Interfaces/Queue.h
        ../Linear/RingQueue/RingQueue.h
        ../Nodes/SingleLinkNode.h
        ../Linear/ArrayQueue/ArrayQueue.h
        ../Linear/LinkedQueue/LinkedQueue.h
        QueueProgram.cpp
)

add_executable(
        TreeProgram
        TreeProgram.cpp
        ../Interfaces/Dictionary.h
)