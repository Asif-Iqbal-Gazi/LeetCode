int findMaxConsecutiveOnes(int *nums, int numsSize) {
  int ans = 0, count = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i]) {
      count++;
      if (count > ans) ans = count;
    } else
      count = 0;
  }
  return ans;
}
