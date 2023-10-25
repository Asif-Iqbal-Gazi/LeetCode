/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
        */

        int n = s.size();
        int m = t.size();

        if (n > m) return false;

        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (j < n && s[j] == t[i])
                j++;
            i++;
        }

        return j == n;
    }
}
// @lc code=end
