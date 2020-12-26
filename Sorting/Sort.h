#ifndef __SORT_H__
#define __SORT_H__

#include <functional>

template <typename T>
using Comparator = std::function<bool(T, T)>;

template<typename T>
void insertionSort(T array[], int n, const Comparator<T> &comp = std::less<T>());

template<typename T>
void bubbleSort(T array[], int n, const Comparator<T> &comp = std::less<T>());

template<typename T>
void selectionSort(T array[], int n, const Comparator<T> &comp = std::less<T>());

#include "InsertionSort.inl"
#include "BubbleSort.inl"
#include "SelectionSort.inl"

#endif // __INSERTION_SORT_H__
