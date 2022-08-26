/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N*M), S.C: O(1)
            2. Binary Search -- T.C: O(log N + log M), S.C: O(1)
                First applying B.Search figure out the row, then apply binary search on that row
            3. Binary Search -- T.C: O(log N + log M), S.C: O(1)
                Treat the complete matrix as a big contiguous array from [0, n*m-1],
                Calculate mid, then do mid/m to get the corresponding row index and mid%m to get the corresponding column index
        */

        /* Approach 1
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
        */

        /* Approach 2
        int n = matrix.size();
        int m = matrix[0].size();
        // Search on last Col
        int l = 0;
        int h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (target > matrix[mid][m - 1])
                l = mid + 1; // Target is greater than last element in mid row.
            else if (target < matrix[mid][0])
                h = mid - 1; // Target is less than first element in mid row.
            else
                break; // Target either exists in mid row or not in matrix.
        }
        // Check if we went out of bound
        if (l > h)
            return false;
        int targetRow = l + (h - l) / 2;
        l = 0;
        h = m - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (matrix[targetRow][mid] == target)
                return true;
            else if (matrix[targetRow][mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
        */

        // Approach 3
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int h = n * m - 1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (matrix[mid / m][mid % m] == target)
                return true;
            else if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
    }
};
// @lc code=end
