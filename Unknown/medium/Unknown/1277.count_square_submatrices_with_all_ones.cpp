/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(m * n), S.C: O(m * n)
            2. DP (Space Optimised) -- T.C: O(m * n), S.C: O(m * n)
        */

        /*
            Can't think of a direct DP state for the problem.

            DP State:
                dp[i][j] : Maximum length valid sqaure(that contains only '1') in the matrix[i:m][j:n]
                            s.t (i, j) is the top corner of the sqaure

            DP Transition:
                if(matrix[i][j] == 0):
                    dp[i][j] = 0;
                else:
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]})

            Base Case:
                dp[0][j] = matrix[0][j] for all j
                dp[i][0] = matrix[i][0] for all i

            Main Problem:
                sum (dp[i][j]) for all i, j
        */

        // Approach 2
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> curr(n, 0);
        vector<int> prev(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    curr[j] = matrix[i][j];
                }
                else if (matrix[i][j] == 0)
                    curr[j] = 0;
                else
                {
                    curr[j] = 1 + min({prev[j - 1], prev[j], curr[j - 1]});
                }
                ans += curr[j];
            }
            prev = curr;
        }
        return ans;

        /* Approach 1
        int m = matrix.size();
        int n = matrix[0].size();

        int dp[m][n];
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                }
                else if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
                ans += dp[i][j];
            }
        }
        return ans;
        */
    }
};
// @lc code=end
