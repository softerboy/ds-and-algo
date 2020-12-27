SET(SORTING_HEADERS ../Sort.h ../Utils.h)

add_executable(InsertionSort ${SORTING_HEADERS} InsertionSort.cpp)
add_executable(BubbleSort ${SORTING_HEADERS} BubbleSort.cpp)
add_executable(SelectionSort ${SORTING_HEADERS} SelectionSort.cpp)
add_executable(ShellSort ${SORTING_HEADERS} ShellSort.cpp)
