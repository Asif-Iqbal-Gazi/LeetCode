/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 */

// @lc code=start
class Solution {
   public:
    int balancedString(string s) {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        int n = s.size();
        int freqMap[26] = {0};
        int left = 0, right = 0, res = n, k = n / 4;

        // Build freqMap for s
        for (char c : s) freqMap[c - 'A']++;

        // Check if s is already balanced
        if (freqMap[22] == k && freqMap[17] == k && freqMap[16] == k && freqMap[4] == k)
            return 0;

        for (right = 0; right < n; right++) {
            // Decrement freqMap for s[right]
            freqMap[s[right] - 'A']--;

            // Check if s is balanced
            // s will be balanced if max freq of any char is <= k
            while (left < n && freqMap[22] <= k && freqMap[17] <= k && freqMap[16] <= k && freqMap[4] <= k) {
                res = min(res, right - left + 1);
                // Increment freqMap for s[left]
                freqMap[s[left] - 'A']++;
                left++;
            }
        }

        return res;
    }
};
// @lc code=end
