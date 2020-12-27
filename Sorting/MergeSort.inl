template <typename T>
void mergeSort(T array[], T temp[], int left, int right, const Comparator<T> &comp) {
  if (left == right) return;

  int mid = (left + right) / 2;
  mergeSort(array, temp, left, mid);
  mergeSort(array, temp, mid + 1, right);

  for (int i = left; i <= right; i++) // copy subarray to temp
    temp[i] = array[i];

  // do merge operation back to array
  int i1 = left, i2 = mid + 1;
  for (int curr = left; curr <= right; curr++) {
    if (i1 == mid + 1)  // left subarray exhausted
      array[curr] = temp[i2++];
    else if (i2 > right) // right subarray exhausted
      array[curr] = temp[i1++];
    else if (comp(temp[i1], temp[i2]))
      array[curr] = temp[i1++];
    else
      array[curr] = temp[i2++];
  }
}
