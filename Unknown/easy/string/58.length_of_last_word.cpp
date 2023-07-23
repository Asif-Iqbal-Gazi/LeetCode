/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
        */

        int l = 0, r = 0, n = s.size();
        // Remove all leading and extra zeros in between
        while (r < n)
        {
            if (s[r] != ' ')
                s[l++] = s[r++];
            else if (r > 0 && s[r - 1] != ' ')
                s[l++] = s[r++];
            else
                r++;
        }
        // Figureout how many chars to delete from left
        // Check if we have a trailing zero
        if (s[l - 1] == ' ')
            l--;
        int noOfCharsToRemove = n - l + 1;
        // Remove all trailing zeros & unnecessary chars
        while (--noOfCharsToRemove)
        {
            s.pop_back();
        }
        // Fix left and right pointer
        n = s.size();
        r = n - 1;
        l = r;
        // Find the length of last word
        while (l >= 0 && s[l] != ' ')
            l--;

        return r - l;
    }
};
// @lc code=end
