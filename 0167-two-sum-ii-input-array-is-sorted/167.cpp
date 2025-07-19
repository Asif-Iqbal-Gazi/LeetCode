class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    /* Approach:
     *  1. [Two Pointer] -- T.C: O(N), S.C: (1)
     *      - The array is sorted.
     *      - Move left pointer rightwards to increase sum; and right pointer leftwards to decrease
     * sum.
     *      - Stop when sum == target.
     */

    int left  = 0;
    int right = numbers.size() - 1;

    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target)
        return {left + 1, right + 1};
      else if (sum < target)
        left++;
      else
        right--;
    }
    return {};
  }
};
