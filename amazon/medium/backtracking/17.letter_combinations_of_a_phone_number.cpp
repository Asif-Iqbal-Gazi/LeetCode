/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
private:
    void solve(int sIndex, string &curr, string &digits, vector<string> &map, vector<string> &ans)
    {
        if (curr.size() == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < map[digits[sIndex] - '0' - 2].size(); i++)
        {
            curr.push_back(map[digits[sIndex] - '0' - 2][i]);
            solve(sIndex + 1, curr, digits, map, ans);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        /* Approach
            Recursion + Backtracking
        */
        if (digits.size() == 0)
            return {};
        string curr = "";
        vector<string> ans;
        vector<string> map(8, "");
        map[0] = "abc";
        map[1] = "def";
        map[2] = "ghi";
        map[3] = "jkl";
        map[4] = "mno";
        map[5] = "pqrs";
        map[6] = "tuv";
        map[7] = "wxyz";
        solve(0, curr, digits, map, ans);
        return ans;
    }
};
// @lc code=end
