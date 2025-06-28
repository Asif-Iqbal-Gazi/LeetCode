/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
  /* Approach:
     1. [Simulation] -- T.C: O(N), S.C: O(1)
        - Initialize carry = 1, since we're adding one.
        - Traverse digits from right to left.
        - Update digit = (digit + carry) % 10; update carry = sum / 10
        - If carry remain, insert it at the beginning.
  */
  int sum   = 0;
  int carry = 1;

  for (int i = digitsSize - 1; i >= 0; i--) {
    sum       = digits[i] + carry;
    carry     = sum / 10;
    digits[i] = sum % 10;
  }
  *returnSize = digitsSize + (carry ? 1 : 0);
  int *res    = (int *)malloc((*returnSize) * sizeof(int));
  res[0]      = carry;

  for (int i = 0; i < digitsSize; i++) {
    res[i + carry] = digits[i];
  }
  return res;
}
