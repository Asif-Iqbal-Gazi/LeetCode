int removeDuplicates(int *nums, int numsSize) {
  // Approach: Two Pointers

  int pos = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] != nums[pos - 1]) {
      nums[pos++] = nums[i];
    }
  }
  return pos;
}
