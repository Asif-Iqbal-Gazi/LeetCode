int lengthOfLongestSubstring(char *s) {
    /*
     * Approach:
     * 1. Brute Force           -- T.C: O(N^2), S.C: O(N)
     *      - Check every possible substring for uniqueness.
     * 2. Sliding Window + Set  -- T.C: O(N),   S.C: O(N)
     *      - Expand right, shrink left on duplicate.
     * 3. Sliding Window + Map  -- T.C: O(N),   S.C: O(N)
     *      - Jump left directly to lastSeen[s[r]] + 1 on duplicate.
     */

    // Approach 3 -- Sliding Window + Map
    int lastSeen[128] = {0};
    memset(lastSeen, -1, sizeof(lastSeen));
    int maxLen = 0;
    int l      = 0;
    for (int r = 0; s[r] != '\0'; r++) {
        if (lastSeen[(int)s[r]] >= l)
            l = lastSeen[(int)s[r]] + 1;
        lastSeen[(int)s[r]] = r;
        if (r - l + 1 > maxLen)
            maxLen = r - l + 1;
    }
    return maxLen;

    /* Approach 2 -- Sliding Window + Set
    bool inWindow[128] = {false};
    int maxLen = 0;
    int l      = 0;
    for (int r = 0; s[r] != '\0'; r++) {
        while (inWindow[(int)s[r]])
            inWindow[(int)s[l++]] = false;
        inWindow[(int)s[r]] = true;
        if (r - l + 1 > maxLen)
            maxLen = r - l + 1;
    }
    return maxLen;
    */

    /* Approach 1 -- Brute Force
    int n      = strlen(s);
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        bool seen[128] = {false};
        for (int j = i; j < n; j++) {
            if (seen[(int)s[j]])
                break;
            seen[(int)s[j]] = true;
            if (j - i + 1 > maxLen)
                maxLen = j - i + 1;
        }
    }
    return maxLen;
    */
}
