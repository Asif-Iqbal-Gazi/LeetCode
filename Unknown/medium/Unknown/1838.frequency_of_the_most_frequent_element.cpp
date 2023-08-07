/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
class Solution {
   public:
    int maxFrequency(vector<int>& nums, long long k) {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
                -- Sort the array
                -- Maintain a sliding window of size 'l' to 'r'
                -- We will try to make all elements in the window equal to nums[r]
                    We will keep a running sum to get the sum of the window
                    Condition, we can make all elements in the window equal to nums[r] in <= k operations:
                    runningSum + k >= (r - l + 1) * nums[r]
                -- While the above condition is true, we will increment 'r' to expand the window
                -- If the above condition is false, we will increment 'l' to slide the window
                    Note: We will also subtract nums[l] from the runningSum, and in the next iteration we will add nums[r]
                        Thus, we maintain a valid window size (Not necessarily, a valid window) at all times
                        Also, this window size is the frequency of nums[r] in the valid window
        */

        // Approach 1 -- Sliding Window
        int i = 0, j = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long runningSum = 0;
        for (j = 0; j < n; j++) {
            runningSum += nums[j];

            if (runningSum + k < 1LL * (j - i + 1) * nums[j]) {
                runningSum -= nums[i];
                i++;
            }
        }
        return j - i;
    }
};
// @lc code=end
