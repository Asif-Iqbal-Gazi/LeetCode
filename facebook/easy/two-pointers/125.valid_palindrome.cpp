/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        /* Approach:
            1. Two Pointers -- T.C: O(N), S.C: O(1)
                First converts to lowercase only string, then use two pointers
        */

        int n = s.size();
        string res = "";

        for (int i = 0; i < n; i++)
        {
            // Uppercase
            if (s[i] >= 65 && s[i] <= 90)
                res += (s[i] + 32);
            // Lowercase
            else if (s[i] >= 97 && s[i] <= 122)
                res += s[i];
            // Numbers
            else if (s[i] >= 48 && s[i] <= 57)
                res += s[i];
        }

        // Two pointer to check
        int l = 0, r = res.size() - 1;

        while (l < r)
        {
            if (res[l++] != res[r--])
                return false;
        }
        return true;
    }
};
// @lc code=end
