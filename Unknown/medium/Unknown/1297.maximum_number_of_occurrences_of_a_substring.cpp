/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 */

// @lc code=start
class Solution {
   private:
    int K;
    int maxFreqSubstringOfLenXandKUnique(string const &s, int x) {
        int ans = 0;
        int l = 0, r = 0, n = s.size();

        int uCount = 0;
        int charFreq[26] = {0};
        unordered_map<string, int> mp;
        for (r = 0; r < n; r++) {
            if (++charFreq[s[r] - 'a'] == 1) uCount++;

            if (r - l + 1 == x) {
                if (uCount <= K) {
                    string key = s.substr(l, r - l + 1);
                    mp[key]++;
                    // cout << key << endl;
                    ans = max(ans, mp[key]);
                }
                if (--charFreq[s[l] - 'a'] == 0) uCount--;
                l++;
            }
        }
        return ans;
    }

   public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
            2. Sliding Window (Optimised) -- T.C: O(n), S.C: O(1)
                -- Observe that, uniqueChar requirement is loose in the sense, it is an upper bound.
                -- So, we will always get our answer from the minSize
        */

        // Approach 2 -- Sliding Window (Optimised)
        K = maxLetters;
        return maxFreqSubstringOfLenXandKUnique(s, minSize);

        /* Approach 1 -- Sliding Window
        K = maxLetters;
        int ans = 0, n = s.size();
        int currMax = 0;
        for (int i = minSize; i <= maxSize; i++) {
            currMax = maxFreqSubstringOfLenXandKUnique(s, i);
            ans = max(ans, currMax);
        }
        return ans;
        */
    }
};
// @lc code=end
