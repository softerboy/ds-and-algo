template<typename T>
void insertionSort(T array[], int n, const std::function<bool(T, T)> &comp) {
  for (int i = 1; i < n; i++) {
    for (int j = i; (j > 0) && comp(array[j], array[j - 1]); j--) {
      swap(array, j, j - 1);
    }
  }
}