/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
private:
    /*
    int solveTopDown(int currIndx, int prevIndx, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (currIndx == nums.size())
            return 0;

        int &currLen = dp[currIndx][prevIndx + 1];
        if (currLen != -1)
            return currLen;
        currLen = solveTopDown(currIndx + 1, prevIndx, nums, dp);
        if (prevIndx == -1 || nums[currIndx] > nums[prevIndx])
            currLen = max(currLen, 1 + solveTopDown(currIndx + 1, currIndx, nums, dp));

        return currLen;
    }
    */
    /*
    int solveRec(int currIndx, int prevIndx, vector<int> &nums)
    {
        if (currIndx == nums.size())
            return 0;

        int currLen = solveRec(currIndx + 1, prevIndx, nums);
        if (prevIndx == -1 || nums[currIndx] > nums[prevIndx])
            currLen = max(currLen, 1 + solveRec(currIndx + 1, currIndx, nums));

        return currLen;
    }
    */

public:
    int lengthOfLIS(vector<int> &nums)
    {
        /* Approach:
            1. Recursion -- T.C: O(2^n), S.C: O(n)
            2. DP (Top Down) -- T.C: O(n^2), S.C: O(n^2)
            3. DP (Bottom Up) -- T.C: O(n^2), S.C: O(n)
            4. Binary Search -- T.C: O(n * log n)
        */

        // Approach 4 -- Binary Search + DP
        vector<int> seen;

        for (int x : nums)
        {
            if (seen.empty() || seen.back() < x)
                seen.push_back(x);
            else
            {
                auto it = lower_bound(seen.begin(), seen.end(), x);
                *it = x;
            }
        }

        return seen.size();

        /* Approach 3 -- DP (Bottom Up)
        // DP State:
        //     dp[i]: LIS till index i s.t, i'th element is part of LIS
        // DP Transition:
        //     dp[i]: max(dp[i], 1 + (dp[j]), if nums[i] > nums[j], for all j [0, i - 1]
        //             1, otherwise
        // Base Case:
        //     dp[0] = 1
        // Final Problem:
        //     max(dp[i]) for all i

        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = dp[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
        */

        /* Approach 2 -- DP (Top Down)
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveTopDown(0, -1, nums, dp);
        */

        /* Approach 1 -- Recursion
        return solveRec(0, -1, nums);
        */
    }
};
// @lc code=end
