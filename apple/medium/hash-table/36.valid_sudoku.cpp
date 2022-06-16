/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        /* Approach:
        1. Unordered_set -- O(N*M), SC: O(N*M)
            While iterrating the matrix form unique string to mark if an element is seen,
            row, column and box-wise.
        */
        unordered_set<string> seen;

        // Build and Check the Set
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Ignore '.'
                if (board[i][j] == '.')
                    continue;
                // Building the unique string
                string num = to_string(board[i][j]);
                string col = "C(" + to_string(j) + ')' + num;
                string row = "R(" + to_string(i) + ')' + num;
                string box = "B(" + to_string(i / 3) + to_string(j / 3) + ')' + num;
                // Check if already present in set
                if (seen.find(col) != seen.end() || seen.find(row) != seen.end() || seen.find(box) != seen.end())
                    // Already seen, return false
                    return false;
                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }
        return true;
    }
};
// @lc code=end
