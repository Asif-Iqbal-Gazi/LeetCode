int minSubArrayLen(int target, int *nums, int numsSize) {
  int left = 0, runningSum = 0;
  int ans = numsSize + 1;

  for (int right = 0; right < numsSize; right++) {
    runningSum += nums[right];
    while (runningSum >= target) {
      int windowLen = right - left + 1;
      if (windowLen < ans)
        ans = windowLen;
      runningSum -= nums[left++];
    }
  }
  return (ans == numsSize + 1) ? 0 : ans;
}
