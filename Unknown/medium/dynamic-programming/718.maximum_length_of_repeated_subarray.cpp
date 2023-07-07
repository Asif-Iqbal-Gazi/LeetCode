/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n * m), S.C: O(n * m)
            2. DP (Space Optimised) -- T.C: O(n * m), S.C: O(m)
        */

        // Approach 2
        int n = nums1.size();
        int m = nums2.size();

        int ans = 0;
        vector<int> prev(m, 0), curr(m, 0);
        // dp[i][j] : Max length common subarray ending at nums1[i] & nums2[j]
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                    curr[j] = 1 + ((i == 0 || j == 0) ? 0 : prev[j - 1]);
                else
                    curr[j] = 0;
                ans = max(ans, curr[j]);
            }
            prev = curr;
        }
        return ans;

        /* Approach 1
        int n = nums1.size();
        int m = nums2.size();

        int dp[n][m];
        int ans = 0;
        // dp[i][j] : Max length common subarray ending at nums1[i] & nums2[j]
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j])
                    dp[i][j] = 1 + ((i == 0 || j == 0) ? 0 : dp[i - 1][j - 1]);
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
        */
    }
};
// @lc code=end
