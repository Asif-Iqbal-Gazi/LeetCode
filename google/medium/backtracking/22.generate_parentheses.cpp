/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
private:
    void solve(int openCount, int closeCount, string &op, vector<string> &res)
    {
        // Base Case
        if (openCount == 0 && closeCount == 0)
        {
            res.push_back(op);
            return;
        }

        // Choice add '('
        if (openCount > 0)
        {
            op.push_back('(');
            solve(openCount - 1, closeCount, op, res);
            // Backtrack
            op.pop_back();
        }

        // Choice add ')'
        if (openCount < closeCount)
        {
            op.push_back(')');
            solve(openCount, closeCount - 1, op, res);
            op.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        /* Approach:
            1. Recursion:
                Draw the recursion tree. Observe that we can add a open bracket '(' any time as long as count of open bracket does not exceed n.
                But we can add a closing bracket as long as we have more open bracket than closing
                We stop our recursion, when we have exhausted all our brackets
        */

        vector<string> res;
        string op = "";
        solve(n, n, op, res);
        return res;
    }
};
// @lc code=end
