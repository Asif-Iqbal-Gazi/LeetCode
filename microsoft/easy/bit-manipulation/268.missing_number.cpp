/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        /* Approach:
            1. Sum [1-n] - Sum of Array -- T.C: O(N), S.C: O(1)
            2. XOR Technique -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++)
            ans ^= i ^ nums[i];

        return ans;

        /* Approach1
        int n = nums.size();

        int sum = (n * (n + 1)) / 2;

        for (int x : nums)
            sum -= x;
        return sum;
        */
    }
};
// @lc code=end
