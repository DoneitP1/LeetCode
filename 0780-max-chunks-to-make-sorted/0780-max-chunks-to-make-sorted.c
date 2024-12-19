int maxChunksToSorted(int* arr, int arrSize) {
  int position = 0, max = 0, count = 0;
  while (arrSize) {
    if (*arr > max) max = *arr;
    ++position; ++arr; --arrSize;
    if (position > max) ++count;
  }
  return count;
}