/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        /* Approach:
            1. Using Prefix & Suffix Product -- T.C: O(n), S.C: O(n) -- 3 Pass
            2. Using Prefix & SUffix Product -- T.C: O(n), S.C: O(1) -- 2 Pass
        */

        // Approach 2
        int n = nums.size();

        vector<int> ans(n, 1);

        // Build the prefix array in ans
        ans[1] = nums[0];
        for (int i = 2; i < n; i++)
            ans[i] = nums[i - 1] * ans[i - 1];

        // Build the suffix
        int suffix = nums[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            ans[j] = ans[j] * suffix;
            suffix *= nums[j];
        }
        return ans;

        /* Approach 1
        int n = nums.size();

        vector<int> pre(n, 1);
        vector<int> suff(n, 1);
        vector<int> ans(n, 1);

        // Build prefix product array
        pre[1] = nums[0];
        for (int i = 2; i < n; i++)
            pre[i] = nums[i - 1] * pre[i - 1];

        // Build suffix product array
        suff[n - 2] = nums[n - 1];
        for (int j = n - 3; j >= 0; j--)
            suff[j] = nums[j + 1] * suff[j + 1];

        // Build ans
        for (int i = 0; i < n; i++)
            ans[i] = pre[i] * suff[i];

        return ans;
        */
    }
};
// @lc code=end
