/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
private:
    void solve(int index, int start, int n, int k, vector<int> &choice, vector<vector<int>> &res)
    {
        // Base Case
        if (index == k)
        {
            res.push_back(choice);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            // choice.push_back(i);
            choice[index] = i;
            solve(index + 1, i + 1, n, k, choice, res);
            // choice.pop_back();
            // Since I am over writing vector as array instead of push back and pop back, no need of backtracking
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        /* Approach:
            1. Recursion
        */
        // vector<int> choice;
        vector<int> choice(k, 0);
        vector<vector<int>> res;
        solve(0, 1, n, k, choice, res);
        return res;
    }
};
// @lc code=end
