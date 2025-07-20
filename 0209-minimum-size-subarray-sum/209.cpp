class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    /* Approach:
     *  1. [Sliding Window] -- T.C: O(N), S.C: O(1)
     *      - Expand right to add nums[right]
     *      - Shrink left to keep sum >= target
     */

    int left  = 0;
    int right = 0;
    int n     = nums.size();
    int ans   = n + 1;

    int runningSum = 0;
    for (right = 0; right < n; right++) {
      runningSum += nums[right];

      while (runningSum >= target) {
        ans = min(ans, right - left + 1);
        runningSum -= nums[left++];
      }
    }

    return ans % (n + 1);
  }
};
