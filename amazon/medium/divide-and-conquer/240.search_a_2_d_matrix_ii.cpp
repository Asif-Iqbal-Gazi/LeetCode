/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution
{
private:
    bool searchMatrix(vector<vector<int>> &matrix, int r, int c, int target)
    {
        if (r >= matrix.size() || c < 0)
            return false;
        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] < target)
            return searchMatrix(matrix, r + 1, c, target);
        else
            return searchMatrix(matrix, r, c - 1, target);
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        /* Approach:
            1. Recursion -- T.C: O(M+N)
            2. Iterative -- T.C: O(M+N), S.C: O(1)
            Start from [0, maxCol -1], if target is greater increment row, if less decrement col
        */

        /* Approach 1
        int r = matrix.size();
        int c = matrix[0].size();
        return searchMatrix(matrix, 0, c - 1, target);
        */

        // Approach 2
        int r = matrix.size();
        int c = matrix[0].size();

        int i = 0;
        int j = c - 1;

        while (i < r && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};
// @lc code=end
