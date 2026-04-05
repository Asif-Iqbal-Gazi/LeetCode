class Solution {
  private:
    // Returns {start, length} of longest palindrome centered at l, r
    pair<int, int> expand(const string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return {l + 1, r - l - 1};
    }

  public:
    string longestPalindrome(string s) {
        /*
         * Approach:
         * 1. Brute Force            -- T.C: O(N^3), S.C: O(1)
         *      - Check every substring for palindrome property.
         * 2. Dynamic Programming    -- T.C: O(N^2), S.C: O(N^2)
         *      - dp[i][j] = true if s[i..j] is a palindrome.
         * 3. Expand Around Center   -- T.C: O(N^2), S.C: O(1)
         *      - Expand outward from each center for odd and even lengths.
         * 4. Manacher's Algorithm   -- T.C: O(N),   S.C: O(N)
         *      - Use previously computed radii to skip redundant comparisons.
         */

        // Approach 3 -- Expand Around Center
        int start  = 0;
        int maxLen = 1;
        for (int i = 0; i < s.size(); i++) {
            // Odd length
            auto [l1, len1] = expand(s, i, i);
            // Even length
            auto [l2, len2] = expand(s, i, i + 1);
            if (len1 > maxLen) {
                maxLen = len1;
                start  = l1;
            }
            if (len2 > maxLen) {
                maxLen = len2;
                start  = l2;
            }
        }
        return s.substr(start, maxLen);

        /* Approach 4 -- Manacher's Algorithm
        int    n = s.size();
        string t = "#";
        for (char c : s) { t += c; t += '#'; }
        int m = t.size();
        vector<int> p(m, 0);
        int c = 0, r = 0;
        for (int i = 0; i < m; i++) {
            int mirror = 2 * c - i;
            if (i < r) p[i] = min(p[mirror], r - i);
            while (i + p[i] + 1 < m && i - p[i] - 1 >= 0 &&
                   t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;
            if (i + p[i] > r) { c = i; r = i + p[i]; }
        }
        int maxLen = *max_element(p.begin(), p.end());
        int center = max_element(p.begin(), p.end()) - p.begin();
        int start  = (center - maxLen) / 2;
        return s.substr(start, maxLen);
        */

        /* Approach 2 -- Interval DP
         * DP State:
         *       dp[i][j] = true if substring s[i..j] is a palindrome
         * DP Transition:
         *       dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]
         * Base Case:
         *       dp[i][i] = true (signle character is always a palindrome)
         *       dp[i][i + 1] = (s[i] == s[i + 1]) (two character substring)
         */
        /*
        int                  n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int                  left = 0, right = 1;

        // Base Case 1: Signle Characters
        for (int i = 0; i < n; i++) dp[i][i] = true;

        // Base Case 2: two character substrings
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                left         = i;
                right        = i + 1;
            }
        }

        // Fill for lengths 3 and above
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    left     = i;
                    right    = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
        */

        /* Approach 1 -- Brute Force
        int n = s.size(), start = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = i, r = j;
                bool isPalin = true;
                while (l < r) {
                    if (s[l++] != s[r--]) { isPalin = false; break; }
                }
                if (isPalin && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    start  = i;
                }
            }
        }
        return s.substr(start, maxLen);
        */
    }
};
