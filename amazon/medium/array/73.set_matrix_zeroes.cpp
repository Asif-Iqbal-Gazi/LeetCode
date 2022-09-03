/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        /* Approach:
            1. Navie Method with Array-- T.C: O(M*N), S.C: O(M+N)
            2. Naive Method with Set-- T.C: O(M*N), S.C: O(M+N)
            3. Optimal Approach -- T.C: O(M*N), S.C: O(1)
        */

        // Approach 3
        // This is based on approach 1, we will use the first row and first col as our map
        int m = matrix.size();
        int n = matrix[0].size();

        int firstCol = 1;

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                firstCol = 0;
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (firstCol == 0)
                matrix[i][0] = 0;
        }

        /* Approach 1
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMap(m, 0);
        vector<int> colMap(n, 0);

        // Iterate over the matrix to build the maps
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowMap[i] = 1;
                    colMap[j] = 1;
                }
            }
        }

        // Now traverse the matrix again
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rowMap[i] || colMap[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
        */

        /* Approach 2
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> rowMap;
        unordered_set<int> colMap;

        // Building the maps
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Prepare our set
                    rowMap.insert(i);
                    colMap.insert(j);
                }
            }
        }

        // Iterate the matrix again to fill zeros
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rowMap.find(i) != rowMap.end() || colMap.find(j) != colMap.end())
                    matrix[i][j] = 0;
            }
        }
        */
    }
};
// @lc code=end
