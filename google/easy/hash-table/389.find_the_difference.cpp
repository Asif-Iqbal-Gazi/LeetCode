/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
   public:
    char findTheDifference(string s, string t) {
        /* Approach:
            1. CharMap -- T.C: O(n + m), S.C: O(1)
            2. Bit Manipulation -- T.C: O(n + n), S.C: O(1)
        */

        // Approach 2 -- Bit Manipulation
        char ans = 0;

        for (char c : s) ans ^= c;

        for (char c : t) ans ^= c;

        return ans;

        /* Approach 1 -- CharMap
        int charMap[26] = {0};

        for (char c : s) charMap[c - 'a']++;

        for (char c : t) {
            if (--charMap[c - 'a'] == -1)
                return c;
        }

        return 'a';
        */
    }
};
// @lc code=end
