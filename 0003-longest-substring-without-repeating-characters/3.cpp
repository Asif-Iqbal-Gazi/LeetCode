class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        /*
         * Approach:
         * 1. Brute Force           -- T.C: O(N^2), S.C: O(N)
         *      - Check every possible substring for uniqueness.
         * 2. Sliding Window + Set  -- T.C: O(N),   S.C: O(N)
         *      - Expand right, shrink left on duplicate.
         * 3. Sliding Window + Map  -- T.C: O(N),   S.C: O(N)
         *      - Jump left directly to lastSeen[s[r]] + 1 on duplicate.
         * 4. Sliding Window + Map (Different approach) -- T.C: O(N), SC: O(1)
         *      - Fixed size ASCII array instead of hash map -> true O(1) space.
         *      - Maintain the maximum window length, move both the pointer only
         *      if window contain repeatition
         */

        // Approach 4 -- Sliding Window + Map (Different Approach)
        int l = 0, r = 0;
        int uniqueCount  = 0;
        int charMap[128] = {0};

        for (r = 0; s[r]; r++) {
            if (++charMap[s[r]] == 1)
                uniqueCount++;
            if (uniqueCount < r - l + 1) {
                if (--charMap[s[l]] == 0)
                    uniqueCount--;
                l++;
            }
        }
        return r - l;

        /* Approach 3 -- Sliding Window + Map
        unordered_map<char, int> lastSeen;
        int                      maxLen = 0;
        int                      l      = 0;
        for (int r = 0; r < s.size(); r++) {
            if (lastSeen.count(s[r]) && lastSeen[s[r]] >= l)
                l = lastSeen[s[r]] + 1;
            lastSeen[s[r]] = r;
            maxLen         = max(maxLen, r - l + 1);
        }
        return maxLen;
        */

        /* Approach 2 -- Sliding Window + Set
        unordered_set<char> inWindow;
        int maxLen = 0;
        int l      = 0;
        for (int r = 0; r < s.size(); r++) {
            while (inWindow.count(s[r]))
                inWindow.erase(s[l++]);
            inWindow.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
        */

        /* Approach 1 -- Brute Force
        int n      = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (seen.count(s[j])) break;
                seen.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
        */
    }
};
