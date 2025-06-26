int findMaxConsecutiveOnes(int *nums, int numsSize) {
  int left       = 0;
  int zero_count = 0;

  for (int right = 0; right < numsSize; right++) {
    if (nums[right] == 0)
      zero_count++;
    if (zero_count > 1) {
      if (nums[left] == 0)
        zero_count--;
      left++;
    }
  }
  return numsSize - left;
}
