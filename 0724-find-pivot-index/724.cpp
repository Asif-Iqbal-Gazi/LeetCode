class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    /* Approach:
         1. Prefix Sum -- T.C: O(N), S.C: O(1)
            - Subtract current element from total sum to get right sum, compare with left sum.
    */

    int left_sum  = 0;
    int right_sum = 0;
    int n         = nums.size();

    // Find the the sum
    for (int num : nums) {
      right_sum += num;
    }

    // Simultatneously find left sum and check if left_sum == right_sum
    for (int i = 0; i < n; i++) {
      right_sum -= nums[i];
      if (left_sum == right_sum)
        return i;
      left_sum += nums[i];
    }
    return -1;
  }
};
