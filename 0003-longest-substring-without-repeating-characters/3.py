# Python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Approach:
        1. Brute Force           -- T.C: O(N^2), S.C: O(N)
             - Check every possible substring for uniqueness.
        2. Sliding Window + Set  -- T.C: O(N),   S.C: O(N)
             - Expand right, shrink left on duplicate.
        3. Sliding Window + Map  -- T.C: O(N),   S.C: O(N)
             - Jump left directly to lastSeen[s[r]] + 1 on duplicate.
        """

        # Approach 3 -- Sliding Window + Map
        last_seen = {}
        max_len = 0
        l = 0
        for r, c in enumerate(s):
            if c in last_seen and last_seen[c] >= l:
                l = last_seen[c] + 1
            last_seen[c] = r
            max_len = max(max_len, r - l + 1)
        return max_len

        # Approach 2 -- Sliding Window + Set
        # in_window = set()
        # max_len   = 0
        # l         = 0
        # for r, c in enumerate(s):
        #     while c in in_window:
        #         in_window.remove(s[l])
        #         l += 1
        #     in_window.add(c)
        #     max_len = max(max_len, r - l + 1)
        # return max_len

        # Approach 1 -- Brute Force
        # max_len = 0
        # for i in range(len(s)):
        #     seen = set()
        #     for j in range(i, len(s)):
        #         if s[j] in seen:
        #             break
        #         seen.add(s[j])
        #         max_len = max(max_len, j - i + 1)
        # return max_len
