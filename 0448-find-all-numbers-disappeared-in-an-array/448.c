/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize) {
  // In C we don't have dynamic containers like in C++/Python/Rust.
  // To avoid over-allocating memory, we estimate the number of missing elements
  // using this key observation:
  // - The number of missing values == number of repeated values
  //  (since the array contains n elements with values in [1, n])
  // We coutn how many times we hit a number that was already marked negative,
  // which indicates a repeat, and use that to allocate exact space for the result.
  int repeat_count = 0;
  for (int i = 0; i < numsSize; i++) {
    int index = abs(nums[i]) - 1;
    if (nums[index] > 0)
      nums[index] = -nums[index];
    else
      repeat_count++;
  }

  int *res = (int *)malloc(repeat_count * sizeof(int));

  int count = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0)
      res[count++] = i + 1;
  }

  *returnSize = count;
  return res;
}
