/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        /*
        Approach:
            1. Observe that if we take mirror image at y=x axis

                1 2 3           1 4 7
                4 5 6   -->     2 5 8
                7 8 9           3 6 9

            2. Now if we reverse row wise (mirror image at y axis) we get our desired matrix

                1 4 7           7 4 1
                2 5 8   -->     8 5 2
                3 6 9           9 6 3
        */

        int n = matrix.size();
        // Mirror image at y = x axis
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        // Mirror image at x = mid
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = n - 1;
            while (l < r)
                swap(matrix[i][l++], matrix[i][r--]);
        }
    }
};
// @lc code=end
