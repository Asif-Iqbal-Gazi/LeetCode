bool isPalindrome(char *s) {
    /*
     * Approach:
     * 1. Two Pointers -- T.C: O(N), S.C: O(1)
     *      - Use two pointers, skip non-alphanumeric, compare lowercase.
     * 2. String Filtering -- T.C: O(N), S.C: O(N)
     *      - Build filtered lowercase string and compare with reverse.
     */

    // Approach 1 -- Two Pointers
    int l = 0, r = strlen(s) - 1;

    while (l < r) {
        while (l < r && !isalnum((unsigned char)s[l])) l++;
        while (l < r && !isalnum((unsigned char)s[r])) r--;

        if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r]))
            return false;

        l++;
        r--;
    }

    return true;

    /* Approach 2 -- String Filtering
    int n = strlen(s);
    char *t = (char *)malloc(n + 1);
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (isalnum((unsigned char)s[i]))
            t[k++] = tolower((unsigned char)s[i]);
    }
    t[k] = '\0';

    int l = 0, r = k - 1;
    while (l < r) {
        if (t[l++] != t[r--]) {
            free(t);
            return false;
        }
    }

    free(t);
    return true;
    */
}
