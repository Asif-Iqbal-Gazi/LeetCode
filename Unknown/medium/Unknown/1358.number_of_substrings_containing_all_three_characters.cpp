/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
   public:
    int numberOfSubstrings(string s) {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(1)
            2. Sliding Window -- T.C: O(n), S.C: O(1)
            3. Same approach as above but slight different implementation -- T.C: O(n), S.C: O(1)
        */

        // Approach 3 -- Sliding Window (Different Implementation)
        int ans = 0;
        int n = s.size();
        int l = 0, r = 0;

        int charMap[3] = {0};
        while (r < n) {
            charMap[s[r] - 'a']++;

            while (l < r && charMap[0] && charMap[1] && charMap[2]) {
                charMap[s[l] - 'a']--;
                l++;
            }
            // Explanation:
            // We have found a valid subarray: [l, r], if we add s[i] for i in range [0, l)
            // We will still have a valid subarray, thus we add l to our answer
            // Which is the number of subarrays that can be formed ending with 'r'

            ans += l;
            r++;
        }
        return ans;

        /* Approach 2 -- Sliding Window
        int ans = 0;
        int n = s.size();
        int l = 0, r = 0;

        int charMap[3] = {0};
        while (r < n) {
            charMap[s[r] - 'a']++;
            r++;

            while (l < r && charMap[0] && charMap[1] && charMap[2]) {
                 Explanation:
                    Found a valid subarray: [l, r), if we add s[i] for i in range [r, n)
                    We will still have a valid subarray, thus we add (n - r + 1) to our answer
                    Which is the number of subarrays that can be formed starting with 'l'
                    Now, we increment 'l' and remove s[l] from our subarray and check if we have a valid subarray
                ans += n - r + 1;
                charMap[s[l] - 'a']--;
                l++;
            }
        }
        return ans;
        */

        /* Approach 1 -- Bruteforce
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int charMap[3] = {0};
            for (int j = i; j < n; j++) {
                charMap[s[j] - 'a']++;
                if (charMap[0] && charMap[1] && charMap[2])
                    ans++;
            }
        }

        return ans;
        */
    }
};
// @lc code=end
