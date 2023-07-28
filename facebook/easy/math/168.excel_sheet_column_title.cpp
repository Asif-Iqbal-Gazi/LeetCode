/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
        */

        // Approach 1
        string ans = "";

        while (columnNumber)
        {
            columnNumber--;
            ans += (columnNumber % 26) + 'A';
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
