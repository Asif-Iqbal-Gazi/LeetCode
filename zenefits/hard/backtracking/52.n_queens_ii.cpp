/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution
{
private:
    /* Approach 1
    bool isSafe(int row, int col, int n, vector<string> &board)
    {
        int dupRow = row;
        int dupCol = col;

        // Upward Diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // Left
        row = dupRow;
        col = dupCol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Downward Diagonal
        row = dupRow;
        col = dupCol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }
    void totalNQueens(int col, int n, vector<string> &board, vector<vector<string>> &res)
    {
        // Base Case
        if (col == n)
        {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, board))
            {
                board[row][col] = 'Q';
                totalNQueens(col + 1, n, board, res);
                board[row][col] = '.';
            }
        }
    }
    */
    void totalNQueens(int col, int n, int &count, vector<int> &left, vector<int> &upperDaigonal, vector<int> &lowerDiagonal)
    {
        // Base condition
        if (col == n)
        {
            count++;
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (left[row] == 0 && upperDaigonal[(n - 1) + (col - row)] == 0 && lowerDiagonal[row + col] == 0)
            {
                left[row] = 1;
                upperDaigonal[(n - 1) + (col - row)] = 1;
                lowerDiagonal[row + col] = 1;
                totalNQueens(col + 1, n, count, left, upperDaigonal, lowerDiagonal);
                // Backtraking
                left[row] = 0;
                upperDaigonal[(n - 1) + (col - row)] = 0;
                lowerDiagonal[row + col] = 0;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        /* Approach:
            1. Recursion
            2. Optimal Recursion
        */

        /* Approach 1
        vector<vector<string>> res;
        // Building chess board
        string s(n, '.');
        vector<string> board(n, s);
        totalNQueens(0, n, board, res);
        return res.size();
        */

        // Approach 2
        int count = 0;
        // Map to determine safe Queen position
        vector<int> left(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        totalNQueens(0, n, count, left, upperDiagonal, lowerDiagonal);
        return count;
    }
};
// @lc code=end
