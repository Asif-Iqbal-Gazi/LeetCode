/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
class Solution {
   public:
    int minDeletions(string s) {
        /* Approach:
            1. Char Frequncy Map + Sorting -- T.C: O(N), S.C: O(1)
            2. Same as above but different implementation
        */

        // Approach 2
        int charFreq[26] = {0};

        // Build the charFreq map
        for (char c : s)
            charFreq[c - 'a']++;

        // Sort the charFreq map
        sort(charFreq, charFreq + 26);  // O(26 * log 26)

        int ans = 0;
        int maxAllowedFreq = s.size();

        for (int i = 25; i >= 0; i--) {  // O(26)
            if (charFreq[i] == 0) break;
            if (charFreq[i] > maxAllowedFreq) {
                ans += charFreq[i] - maxAllowedFreq;
                charFreq[i] = maxAllowedFreq;
            }
            maxAllowedFreq = charFreq[i] ? charFreq[i] - 1 : 0;
        }

        return ans;

        /* Approach 1
        int charFreq[26] = {0};

        for (char c : s)        // T.C: O(N)
            charFreq[c - 'a']++;

        sort(charFreq, charFreq + 26);

        int ans = 0;
        for (int i = 24; i >= 0; i--) {
            if (charFreq[i] == 0) break;
            if (charFreq[i] == charFreq[i + 1]) {
                ans++;
                charFreq[i]--;
            }
            else if (charFreq[i] > charFreq[i + 1]) {
                if (charFreq[i + 1] == 0) {
                    ans += charFreq[i];
                    charFreq[i] = 0;
                }
                else {
                    ans += charFreq[i] - charFreq[i + 1] + 1;
                    charFreq[i] = charFreq[i + 1] - 1;
                }
            }
        }
        // 2 2 2
        // b b c e b a b
        // 4 1 1 1

        return ans;
        */
    }
};
// @lc code=end
