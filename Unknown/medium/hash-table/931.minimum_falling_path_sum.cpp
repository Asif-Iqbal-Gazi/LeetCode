/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n *m), S.C: O(1)
        */

        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = 0; col < m; col++)
            {
                int minLeftnBottom = min(matrix[row + 1][col],
                                         col > 0 ? matrix[row + 1][col - 1] : INT_MAX);
                matrix[row][col] += min(minLeftnBottom,
                                        col < m - 1 ? matrix[row + 1][col + 1] : INT_MAX);
            }
        }

        for (int col = 0; col < m; col++)
            ans = min(ans, matrix[0][col]);

        return ans;
    }
};
// @lc code=end
