int dominantIndex(int *nums, int numsSize) {
  /* Approach:
     1. [Math Logic] -- T.C: O(N), S.C: O(1)
      - Track largest and second largest elements in a single pass.
      - Return index of the largest if it is at least twice the second largest.
  */

  int index          = 0;
  int largest        = INT_MIN;
  int second_largest = INT_MIN;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > largest) {
      second_largest = largest;
      largest        = nums[i];
      index          = i;
    } else if (nums[i] > second_largest) {
      second_largest = nums[i];
    }
  }

  return (largest >= 2 * second_largest) ? index : -1;
}
