#include <string.h>
char *longestPalindrome(char *s) {
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

    // Approach 2 -- Interval DP
    /* DP State:
     *      dp[i][j] = true if substring s[i..j] is a palindrome
     * DP Transition:
     *      dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]
     * Base Case:
     *      dp[i][i] = true (single character is always a palindrome)
     *      dp[i][i + 1] = (s[i] == s[i + 1]) (two character substring)
     */

    int n     = strlen(s);
    int left  = 0;
    int right = 0;

    bool dp[1000][1000];
    memset(dp, false, sizeof(dp));

    // Base Case 1: Signle character
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // Base Case 2: two character substring
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
    char *result = (char *)malloc((right - left + 2) * sizeof(char));
    strncpy(result, s + left, right - left + 1);
    result[right - left + 1] = '\0';
    return result;

    /* Approach 3 -- Expand Around Center
    int n      = strlen(s);
    int start  = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd length
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start  = l;
            }
            l--;
            r++;
        }
        // Even length
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start  = l;
            }
            l--;
            r++;
        }
    }

    char *result = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
    */

    /* Approach 4 -- Manacher's Algorithm
    int  n   = strlen(s);
    int  m   = 2 * n + 1;
    char *t  = (char *)malloc((m + 1) * sizeof(char));
    int  *p  = (int  *)malloc(m       * sizeof(int));
    t[0] = '#';
    for (int i = 0; i < n; i++) {
        t[2 * i + 1] = s[i];
        t[2 * i + 2] = '#';
    }
    t[m] = '\0';
    int c = 0, r = 0;
    for (int i = 0; i < m; i++) {
        int mirror = 2 * c - i;
        p[i] = (i < r) ? (p[mirror] < r - i ? p[mirror] : r - i) : 0;
        while (i + p[i] + 1 < m && i - p[i] - 1 >= 0 &&
               t[i + p[i] + 1] == t[i - p[i] - 1])
            p[i]++;
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    int maxLen = 0, center = 0;
    for (int i = 0; i < m; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            center = i;
        }
    }
    int start = (center - maxLen) / 2;
    char *result = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    free(t);
    free(p);
    return result;
    */
}
