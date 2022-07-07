/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int countTarget(int i, int sum, vector<int> &nums, int target, vector<unordered_map<int, int>> &dp)
    {
        // Termination Condition
        if (i == nums.size())
            return sum == target ? 1 : 0;
        auto it = dp[i].find(sum);
        if (it != dp[i].end())
            return it->second;
        return dp[i][sum] = countTarget(i + 1, sum + nums[i], nums, target, dp) +
                            countTarget(i + 1, sum - nums[i], nums, target, dp);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        /* Approach:
            1. Recursion Bruteforce -- T.C: O(2^n)
            2. Recursion with Memoization
        */

        // Approach 2 -- Recursion with Memoization
        vector<unordered_map<int, int>> dp(nums.size());
        return countTarget(0, 0, nums, target, dp);

        /* Approach 1
        // Call our recursive function with index = 0 and sum = 0

        return countTarget(0, 0, nums, target);
        */
    }
};
// @lc code=end
