int thirdMax(int *nums, int numsSize) {
  long long first  = LLONG_MIN;
  long long second = LLONG_MIN;
  long long third  = LLONG_MIN;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == first || nums[i] == second || nums[i] == third)
      continue;

    if (nums[i] > first) {
      third  = second;
      second = first;
      first  = nums[i];
    } else if (nums[i] > second) {
      third  = second;
      second = nums[i];
    } else if (nums[i] > third) {
      third = nums[i];
    }
  }
  return (third == LLONG_MIN) ? first : third;
}
