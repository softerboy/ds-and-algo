template<typename T>
void selectionSort(T array[], int n, const Comparator<T> &comp) {
  for (int i = 0; i < n - 1; i++) {
    int lowindex = i;
    for (int j = n - 1; j > i; j--)
      if (comp(array[j], array[lowindex]))
        lowindex = j;
    swap(array, i, lowindex);
  }
}
