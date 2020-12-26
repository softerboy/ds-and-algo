#ifndef __SORT_H__
#define __SORT_H__

#include <functional>

template<typename T>
void insertionSort(T array[], int n, const std::function<bool(T, T)> &comp);

#include "InsertionSort.inl"

#endif // __INSERTION_SORT_H__
