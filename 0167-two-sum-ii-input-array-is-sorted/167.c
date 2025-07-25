/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
  int left  = 0;
  int right = numbersSize - 1;

  while (left < right) {
    int sum = numbers[left] + numbers[right];
    if (sum == target) {
      int *result = (int *)malloc((*returnSize) * sizeof(int));
      result[0]   = left + 1;
      result[1]   = right + 1;
      *returnSize = 2;
      return result;
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  *returnSize = 0;
  return NULL;
}
