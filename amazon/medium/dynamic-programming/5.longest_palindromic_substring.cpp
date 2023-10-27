/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
   private:
    int N;
    int leftIndex;
    int windowLen;
    void longestPalinHelper(const string &s, int l, int r) {
        while (r < N && l >= 0 && s[l] == s[r]) {
            if (r - l + 1 > windowLen) {
                leftIndex = l;
                windowLen = r - l + 1;
            }
            l--;
            r++;
        }
    }

   public:
    string longestPalindrome(string s) {
        /* Approach:
            1. Bruteforce -- T.C: O(N^3), S.C: O(1)
            2. Interval DP -- T.C: O(N^2), S.C: O(N^2)
            3. Expand from middle -- T.C: O(N^2), S.C: O(1)
        */

        // Approach 3 -- Expand from Middle
        N = s.size();
        leftIndex = 0;
        windowLen = 0;

        for (int i = 0; i < N; i++) {
            // Odd palindrome
            longestPalinHelper(s, i, i);
            // Even palindrome
            longestPalinHelper(s, i, i + 1);
        }
        return s.substr(leftIndex, windowLen);

        /* Approach 2 -- Interval DP

        // DP State:
        //     dp[i][j] = If substring s[i:j] is palindorme
        // DP Transition:
        //     if (s[i] == s[j]) and dp[i + 1][j - 1] is true
        //         then dp[i][j] = true;
        // Base Case:
        //     dp[i][i] = true, for i < n

        int n = s.size();
        int left = 0, right =0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Set Base case
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // Deal with even palindrome
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                left = i;
                right = i + 1;
            }
        }

        for (int len = 2; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
        */

        /* Approach 1 -- Bruteforce
        // Idea: Consider all substrings
        int n = s.size();
        int i = 0, j = 0;
        int maxLen = 0;
        int left = 0, right = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (s[l] != s[r]) continue;
                i =l, j = r;
                while(i < j && s[i] == s[j]) i++, j--;
                if (s[i] == s[j] && maxLen < r - l + 1) {
                    left = l;
                    right = r;
                    maxLen = r - l + 1;
                }
            }
        }

        return s.substr(left, maxLen);
        */
    }
};
// @lc code=end
