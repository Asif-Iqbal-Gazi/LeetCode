/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        /* Approach:
            1. Linear Search -- T.C: O(n + m), S.C: O(1)
        */

        // Approach 1 -- Linear Search
        int n = grid.size();
        int m = grid[0].size();

        int i = 0, j = m - 1, count = 0;

        while (i < n && j >= 0) {
            if (grid[i][j] < 0) {
                count += n - i;  // All elements from grid[i][j] --> grid[i][n - 1] will be negative
                j--;
            } else
                i++;
        }
        return count;
    }
};
// @lc code=end
