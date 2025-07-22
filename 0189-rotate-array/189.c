void reverse(int *nums, int start, int end) {
  while (start < end) {
    int temp    = nums[start];
    nums[start] = nums[end];
    nums[end]   = temp;
    start++;
    end--;
  }
}

void rotate(int *nums, int numsSize, int k) {
  k %= numsSize;
  if (k == 0)
    return;
  reverse(nums, 0, numsSize - k - 1);
  reverse(nums, numsSize - k, numsSize - 1);
  reverse(nums, 0, numsSize - 1);
}
