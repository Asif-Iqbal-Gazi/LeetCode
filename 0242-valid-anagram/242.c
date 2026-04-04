/* comparator for qsort */
int cmp(const void *a, const void *b) {
    return (*(const char *)a - *(const char *)b);
}

bool isAnagram(char *s, char *t) {
    /*
     * Approach:
     * 1. Hash Table -- T.C: O(N), S.C: O(1)
     *      - Count frequency of characters in s, decrement using t.
     *        If all counts are zero, strings are anagrams.
     * 2. Sorting -- T.C: O(N log N), S.C: O(1)
     *      - Sort both strings and compare.
     */

    // Approach 1 -- Hash Table
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t)
        return false;

    int count[26] = {0};

    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;

    /* Approach 2 -- Sorting
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t)
        return false;
    qsort(s, len_s, sizeof(char), cmp);
    qsort(t, len_t, sizeof(char), cmp);
    return strcmp(s, t) == 0;
    */
}
