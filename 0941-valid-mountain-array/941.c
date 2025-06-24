bool validMountainArray(int *arr, int arrSize) {
  if (arrSize < 3) return false;

  int i = 0;

  // climb up
  while (i + 1 < arrSize && arr[i] < arr[i + 1]) i++;

  // peak can't be at first or last index
  if (i == 0 || i == arrSize) return false;

  // climb down
  while (i + 1 < arrSize && arr[i] > arr[i + 1]) i++;

  return i == arrSize - 1;
}
