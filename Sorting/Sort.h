#ifndef __SORT_H__
#define __SORT_H__

#include <functional>

template <typename T>
using Comparator = std::function<bool(T, T)>;

template<typename T>
void insertionSort(T array[], int n, const Comparator<T> &comp = std::less<T>());

template <typename T>
void insertionSort2(T array[], int n, int incr, const Comparator<T> &comp = std::less<T>());

template<typename T>
void bubbleSort(T array[], int n, const Comparator<T> &comp = std::less<T>());

template<typename T>
void selectionSort(T array[], int n, const Comparator<T> &comp = std::less<T>());

template <typename T>
void shellSort(T array[], int n, const Comparator<T> &comp = std::less<T>());

template <typename T>
void mergeSort(T array[], T temp[], int left, int right, const Comparator<T> &comp = std::less<T>());

template <typename T>
void quickSort(T array[], int left, int right, const Comparator<T> &comp = std::less_equal<T>());

template <typename T>
void heapSort(T array[], int n, const Comparator<T>& comp = std::less<T>());

#include "InsertionSort.inl"
#include "BubbleSort.inl"
#include "SelectionSort.inl"
#include "ShellSort.inl"
#include "MergeSort.inl"
#include "QuickSort.inl"
#include "HeapSort.inl"

#endif // __INSERTION_SORT_H__
