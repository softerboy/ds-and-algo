template<typename T>
int partition(T array[], int l, int r, const Comparator<T> &comp) {
  auto pivot = array[l];
  int start = l;
  int end = r;

  while (start < end) {
    while (comp(array[start], pivot)) start++;
    while (!comp(array[end], pivot)) end--;

    if (start < end) swap(array, start, end);
  }

  swap(array, l, end);

  return end;
}

template<typename T>
void quickSort(T array[], int left, int right, const Comparator<T> &comp) {
  if (left < right) {
    int loc = partition(array, left, right, comp);
    quickSort(array, left, loc - 1, comp);
    quickSort(array, loc + 1, right, comp);
  }
}