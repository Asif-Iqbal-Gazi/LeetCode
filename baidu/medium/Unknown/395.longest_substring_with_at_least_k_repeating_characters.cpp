/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
   private:
    int getValidWindowSizeWithXUnqiueChar(int k, int uCount, string const &s) {
        int l = 0, ans = 0, n = s.size();

        int charFreq[26] = {0};
        int currUCharCount = 0;
        int currUCharKFreqCount = 0;
        for (int r = 0; r < n; r++) {
            if (++charFreq[s[r] - 'a'] == 1) currUCharCount++;
            if (charFreq[s[r] - 'a'] == k) currUCharKFreqCount++;

            while (currUCharCount > uCount) {
                // Shrink window
                if (charFreq[s[l] - 'a'] == k) currUCharKFreqCount--;
                if (--charFreq[s[l] - 'a'] == 0) currUCharCount--;
                l++;
            }

            if (currUCharCount == currUCharKFreqCount) ans = max(ans, r - l + 1);
        }
        return ans;
    }

   public:
    int longestSubstring(string s, int k) {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(1)
            2. Sliding Window -- T.C: O(n), S.C: O(1)
                Observation:
                    We are asked to find the maximum window, to apply sliding window, we need a logic to move the left pointer
                    -- We can add in a constraint to our problem to create subproblem, which in turn would solve our original problem
                Sub-Problem:
                    -- Find the max window size such that it contains exactly 'x' unique char with frequency at least 'k'
                    -- With the above contraint, we can solve the sub-problem in O(N) T.C:
                    -- As per problem description at max we can have 26 unique chars.
                    -- So, the original problem can be solved in O(N) * 26 time comeplexity
        */

        // Approach 2 -- Sliding Window
        int n = s.size();
        int charFreq[26] = {0};
        int uCharCountKFreq = 0;
        for (char c : s) {  // T.C: O(n)
            if (++charFreq[c - 'a'] == k)
                uCharCountKFreq++;
        }
        // Return early
        if (uCharCountKFreq == 0) return 0;

        /* Observe:
            If we find a valid window of 'x' unique char (each having at least k freq),
            we will not be able say deterministically that, there will be a valid window with 'x - 1' unqiue char
            or vice-versa
            e.g:
                s = "abab", k = 2;
                Here, unique char = 2 --> valid
                unqiue char = 1 --> Not valid
        */

        int result = 0, currResult = 0;
        for (int uCount = 1; uCount <= uCharCountKFreq; uCount++) {  // T.C: O(26 * n)
            currResult = getValidWindowSizeWithXUnqiueChar(k, uCount, s);
            result = max(result, currResult);
        }
        return result;

        /* Approach 1 -- Bruteforce
        int ans = 0;
        int n = s.size();
        int charFreq[26] = {0};

        for (int i = 0; i < n; i++) {
            int uCount = 0;
            int uKCount = 0;
            for (int j = i; j < n; j++) {
                if (++charFreq[s[j] - 'a'] == 1) uCount++;
                if (charFreq[s[j] - 'a'] == k) {
                    cout << s[j] << " ";
                    uKCount++;
                }
                if (uCount == uKCount) ans = max(ans, j - i + 1);
            }
            // Reset Everything
            for (int j = 0; j < 26; j++) charFreq[j] = 0;
        }
        return ans;
        */
    }
};
// @lc code=end
