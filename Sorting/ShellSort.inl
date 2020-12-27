template<typename T>
void insertionSort2(T array[], int n, int incr, const Comparator<T> &comp) {
  for (int i = incr; i < n; i += incr)
    for (int j = i; (j >= incr) && (comp(array[j], array[j - incr])); j -= incr)
      swap(array, j, j - incr);
}

template<typename T>
void shellSort(T array[], int n, const Comparator<T> &comp) {
  for (int gap = n / 2; gap > 2; gap /= 2)
    for (int i = 0; i < gap; i++)
      insertionSort2(&array[i], n - i, gap, comp);
  insertionSort2(array, n, 1, comp);
}