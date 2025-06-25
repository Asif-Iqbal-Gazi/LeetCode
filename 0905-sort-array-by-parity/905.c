/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize) {
  int l    = 0;
  int temp = 0;
  int r    = numsSize - 1;

  int *res_nums = (int *)malloc(numsSize * sizeof(int));
  *returnSize   = numsSize;
  for (int i = 0; i < *returnSize; i++) res_nums[i] = nums[i];

  while (l < r) {
    if (res_nums[l] & 1) {
      temp          = res_nums[l];
      res_nums[l]   = res_nums[r];
      res_nums[r--] = temp;
    } else
      l++;
  }

  return res_nums;
}
