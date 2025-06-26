class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    /* Approach:
       1. [Sliding Window] -- T.C: O(N), S.C: O(1)
          - Expand the window by moving right; if there are more than one zero, move left forward.
            The final window will be the longest with at most one zero.
    */
    int left       = 0;
    int zero_count = 0;
    int n          = nums.size();

    for (int right = 0; right < n; right++) {
      if (nums[right] == 0)
        zero_count++;
      if (zero_count > 1) {
        if (nums[left] == 0)
          zero_count--;
        left++;
      }
    }
    return n - left;
  }
};
