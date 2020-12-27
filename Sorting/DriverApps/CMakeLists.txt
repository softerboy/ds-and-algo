SET(SORTING_HEADERS ../Sort.h ../Utils.h)

add_executable(InsertionSort ${SORTING_HEADERS} InsertionSort.cpp)
add_executable(BubbleSort ${SORTING_HEADERS} BubbleSort.cpp)
add_executable(SelectionSort ${SORTING_HEADERS} SelectionSort.cpp)
add_executable(ShellSort ${SORTING_HEADERS} ShellSort.cpp)
add_executable(MergeSort ${SORTING_HEADERS} MergeSort.cpp)
add_executable(QuickSort ${SORTING_HEADERS} QuickSort.cpp)
add_executable(HeapSort ${SORTING_HEADERS} HeapSort.cpp)
