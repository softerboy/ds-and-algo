add_executable(
        ListProgram
        ../Errors/RangeError.h
        ../Errors/RangeError.cpp
        ../Linear/Interfaces/List.h
        ../Linear/Node/SingleLinkNode.h
        ../Linear/ArrayList/ArrayList.h
        ../Linear/LinkedList/LinkedList.h
        ListProgram.cpp
)

add_executable(
        StackProgram
        ../Linear/Interfaces/Stack.h
        ../Linear/Node/SingleLinkNode.h
        ../Linear/ArrayStack/ArrayStack.h
        ../Linear/LinkedStack/LinkedStack.h
        StackProgram.cpp
)

add_executable(
        QueueProgram
        ../Linear/Interfaces/Queue.h
        ../Linear/Node/SingleLinkNode.h
        ../Linear/ArrayQueue/ArrayQueue.h
        ../Linear/LinkedQueue/LinkedQueue.h
        QueueProgram.cpp
)