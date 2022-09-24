/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution
{
private:
    /*
    bool isSafe(int row, int col, int n, vector<string> &board)
    {
        int duprow = row;
        int dupcol = col;

        // Check left direction
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Check upward diagonal direction
        row = duprow;
        col = dupcol;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // check downward diagonal direction
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solveNQueens(int col, int n, vector<string> &board, vector<vector<string>> &res)
    {
        // Base Case -- When we have reached nth col
        if (col == n)
        {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, board))
            {
                board[row][col] = 'Q';                // If Safe place the queen
                solveNQueens(col + 1, n, board, res); // Try for next column
                board[row][col] = '.';                // Backtracking, so we can try for next row
            }
        }
    }
    */

    void solveNQueens(int col, int n, vector<string> &board, vector<int> &left, vector<int> &upwardDiagonal, vector<int> &downwardDiagonal, vector<vector<string>> &res)
    {
        // Base condition
        if (col == n)
        {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (left[row] == 0 && upwardDiagonal[(n - 1) + (col - row)] == 0 && downwardDiagonal[row + col] == 0)
            {
                board[row][col] = 'Q';
                left[row] = 1;
                upwardDiagonal[(n - 1) + (col - row)] = 1;
                downwardDiagonal[row + col] = 1;
                solveNQueens(col + 1, n, board, left, upwardDiagonal, downwardDiagonal, res);
                // Backtracking
                board[row][col] = '.';
                left[row] = 0;
                upwardDiagonal[(n - 1) + (col - row)] = 0;
                downwardDiagonal[row + col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        /* Approach:
            1. Recursion
            2. Optimal Recursion
        */

        /* Approach 1
        vector<vector<string>> res;
        // Create the chessboard
        string s(n, '.');
        vector<string> board(n);
        for (int i = 0; i < n; i++)
            board[i] = s;

        solveNQueens(0, n, board, res);
        return res;
        */

        vector<vector<string>> res;
        // Creating chessboard
        string s(n, '.');
        vector<string> board(n, s);
        // Set to find safe position (Improves T.C)
        vector<int> left(n, 0); // Basically marks the row-wise position of queen
        vector<int> upwardDiagonal(2 * n - 1, 0);
        vector<int> downwardDiagonal(2 * n - 1, 0);
        solveNQueens(0, n, board, left, upwardDiagonal, downwardDiagonal, res);
        return res;
    }
};
// @lc code=end
