/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        /* Approach:
            1. Bruteforce -- T.C: O(N^3), S.C: O(1)
            2. Sort + 2 Pointers -- T.C: O(N^2), S.C: O(1)
        */

        // Approach 2
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        // Just to speed up a few things
        if (n == 3) return ans;
        sort(nums.begin(), nums.end());  // T.C: O(N * log N)
        ans = nums[0] + nums[1] + nums[2];
        if (target <= ans) return ans;
        ans = nums[n - 1] + nums[n - 2] + nums[n - 3];
        if (target >= ans) return ans;

        int currSum = 0;
        int currDiff = 0;
        int diff = INT_MAX;
        int i = 0, j = 0, k = 0;

        for (i = 0; i < n - 2; i++) {  // T.C: O(N^2)
            j = i + 1;
            k = n - 1;
            while (j < k) {  // T.C: O(N)
                currSum = nums[i] + nums[j] + nums[k];
                currDiff = abs(target - currSum);
                if (target == currSum)
                    return currSum;
                else if (target > currSum)
                    j++;
                else
                    k--;
                if (diff > currDiff) {
                    diff = currDiff;
                    ans = currSum;
                }
            }
        }
        return ans;

        /* Approach 1
        int ans = INT_MAX;
        int diff = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int currSum = nums[i] + nums[j] + nums[k];
                    int currDiff = abs(target - currSum);
                    if (currDiff < diff) {
                        ans = currSum;
                        diff = currDiff;
                    }
                }
            }
        }
        return ans;
        */
    }
};
// @lc code=end
