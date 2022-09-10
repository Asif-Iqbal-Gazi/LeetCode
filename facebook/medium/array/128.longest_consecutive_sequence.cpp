/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        /* Approach:
            1. Sort & Traverse -- T.C: O(nlogn), S.C: O(1)
            2. Using Set -- T.C: O(n), S.C: O(1)
        */

        // Approach 2
        int n = nums.size();
        if (n < 2)
            return n;

        int ans = 0;
        int curr_len = 1;
        unordered_set<int> s(nums.begin(), nums.end());

        for (auto x : s)
        {
            // Are we dealing with starting element of sequence
            if (s.find(x - 1) == s.end())
            {
                curr_len = 1;
                while (s.find(x + 1) != s.end())
                {
                    curr_len++;
                    x++;
                }
                ans = max(curr_len, ans);
            }
        }
        return ans;

        /* Approach 1
        int n = nums.size();
        if (n < 2)
            return n;
        int ans = 0;
        int curr = 1;
        // Sort
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
                curr++;
            // If equal just continue
            else if (nums[i] == nums[i - 1])
                continue;
            else
            {
                ans = max(curr, ans);
                curr = 1;
            }
        }
        // The array might be already sorted
        ans = max(ans, curr);
        return ans;
        */
    }
};
// @lc code=end
