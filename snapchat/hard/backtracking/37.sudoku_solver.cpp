/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution
{
private:
    bool isValid(int row, int col, char choice, vector<vector<char>> &board)
    {
        // Validity check
        for (int i = 0; i < 9; i++)
        {
            // Column wise
            if (board[row][i] == choice)
                return false;
            // Row wise
            if (board[i][col] == choice)
                return false;
            // Grid wise
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == choice)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Check if the cell is empty
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(i, j, c, board))
                        {
                            board[i][j] = c;
                            if (solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
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
