/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution
{
private:
    bool isValid(char c, int row, int col, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check row-wise
            if (board[i][col] == c)
                return false;
            // Check col-wise
            if (board[row][i] == c)
                return false;
            // Check 3x3 board
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        // Using Two Loops iterate over the entire board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    // Found an empty spot
                    for (char c = '1'; c <= '9'; c++)
                    {
                        // Check if we are allowed to place c in this position
                        if (isValid(c, i, j, board))
                        {
                            board[i][j] = c;
                            if (solve(board) == true)
                                return true; // No need to go further in recursion just return true
                            else
                                board[i][j] = '.'; // Backtracking
                        }
                    }
                    // If we were able to solve, we should have returned true by now
                    return false;
                }
            }
        }
        // We have checked the entire board, not empty spot
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        /* Approach:
            1. Recursion
        */
        solve(board);
    }
};
// @lc code=end
