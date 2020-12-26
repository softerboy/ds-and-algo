template <typename T>
void swap(T array[], int i, int j) {
  auto temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

template <typename T>
void printArray(T array[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << " ";
  }
}