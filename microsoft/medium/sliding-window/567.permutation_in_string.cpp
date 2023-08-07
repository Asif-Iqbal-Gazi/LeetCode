/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
            2.
        */

        // Approach 1
        // Edge Case
        if (s1.size() > s2.size())
            return false;

        int uniqueCount = 0;
        int freqMap[26] = {0};
        // Build freqMap for s1
        for (char c : s1) {
            if (freqMap[c - 'a'] == 0)
                uniqueCount++;
            freqMap[c - 'a']++;
        }

        int count = 0;
        int l = 0, r = 0, n = s2.size();

        while (r < n) {
            if (--freqMap[s2[r] - 'a'] == 0)
                uniqueCount--;
            r++;

            // We need to maintain a window of size s1.size()
            while (r - l >= s1.size()) {
                if (uniqueCount == 0)
                    return true;
                if (++freqMap[s2[l] - 'a'] == 1)
                    uniqueCount++;
                l++;
            }
        }
        return false;
    }
};
// @lc code=end
