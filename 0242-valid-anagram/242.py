class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        """
        Approach:
        1. Hash Table -- T.C: O(N), S.C: O(1)
             - char_map frequency of characters in s, decrement using t.
               If all char_maps are zero, strings are anagrams.
        2. Sorting -- T.C: O(N log N), S.C: O(1)
             - Sort both strings and compare.
        """

        # Approach 1 -- Hash Table
        if len(s) != len(t):
            return False

        char_map = [0] * 26

        for i in range(len(s)):
            char_map[ord(s[i]) - ord("a")] += 1
            char_map[ord(t[i]) - ord("a")] -= 1

        for c in char_map:
            if c != 0:
                return False

        return True

        # Approach 2 -- Sorting
        # if len(s) != len(t):
        #     return False
        # return sorted(s) == sorted(t)
