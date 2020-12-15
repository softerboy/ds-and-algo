add_executable(
        ListProgram
        ../Errors/RangeError.h
        ../Errors/RangeError.cpp
        ../Linear/Interfaces/List.h
        ../Linear/ArrayList/ArrayList.h
        ../Linear/LinkedList/LinkedList.h
        ListProgram.cpp
)

add_executable(
        StackProgram
        ../Linear/Interfaces/Stack.h
        ../Linear/ArrayStack/ArrayStack.h
        ../Linear/LinkedStack/LinkedStack.h
        StackProgram.cpp
)