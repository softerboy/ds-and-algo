template<typename T>
void bubbleSort(T array[], int n, const Comparator<T> &comp) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (comp(array[j], array[j - 1])) {
        swap(array, j, j - 1);
      }
    }
  }
}