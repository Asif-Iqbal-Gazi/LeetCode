/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        /* Approach:
            1. Prefix Sum + Map -- T.C: O(n), S.C: O(n)
        */

        int ans = 0;
        int prefixSum = 0;
        int n = nums.size();
        unordered_map<int, int> seen;
        seen[0]++;

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            if (seen.find(prefixSum - k) != seen.end())
                ans += seen[prefixSum - k];
            seen[prefixSum]++;
        }
        return ans;
    }
};
// @lc code=end
