class Solution {
  public:
    bool isAnagram(string s, string t) {
        /*
         * Approach:
         * 1. Hash Table -- T.C: O(N), S.C: O(1)
         *      - Count frequency of characters in s, decrement using t.
         *        If all counts are zero, strings are anagrams.
         * 2. Sorting -- T.C: O(N log N), S.C: O(1)
         *      - Sort both strings and compare.
         */

        // Approach 1 -- Hash Table
        if (s.size() != t.size())
            return false;

        int charMap[26] = {0};

        for (int i = 0; s[i]; i++) {
            charMap[s[i] - 'a']++;
            charMap[t[i] - 'a']--;
        }
        for (int c : charMap) {
            if (c != 0)
                return false;
        }

        return true;

        /* Approach 2 -- Sorting
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        */
    }
};
