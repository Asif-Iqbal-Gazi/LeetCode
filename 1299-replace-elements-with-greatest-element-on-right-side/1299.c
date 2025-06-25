int *replaceElements(int *arr, int arrSize, int *returnSize) {
  int curr      = -1;
  int right_max = -1;
  int r         = arrSize - 1;

  int *res_arr = (int *)malloc(arrSize * sizeof(int));

  while (r >= 0) {
    curr         = arr[r];
    res_arr[r--] = right_max;
    if (curr > right_max) right_max = curr;
  }
  *returnSize = arrSize;
  return res_arr;
}
