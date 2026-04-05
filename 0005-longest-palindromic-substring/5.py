class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        Approach:
        1. Brute Force            -- T.C: O(N^3), S.C: O(1)
             - Check every substring for palindrome property.
        2. Dynamic Programming    -- T.C: O(N^2), S.C: O(N^2)
             - dp[i][j] = true if s[i..j] is a palindrome.
        3. Expand Around Center   -- T.C: O(N^2), S.C: O(1)
             - Expand outward from each center for odd and even lengths.
        4. Manacher's Algorithm   -- T.C: O(N),   S.C: O(N)
             - Use previously computed radii to skip redundant comparisons.
        """

        # Approach 3 -- Expand Around Center
        def expand(l: int, r: int) -> str:
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l + 1 : r]

        result = ""
        for i in range(len(s)):
            odd = expand(i, i)  # odd length
            even = expand(i, i + 1)  # even length
            if len(odd) > len(result):
                result = odd
            if len(even) > len(result):
                result = even
        return result

        # Approach 4 -- Manacher's Algorithm
        # t = '#' + '#'.join(s) + '#'
        # m = len(t)
        # p = [0] * m
        # c = r = 0
        # for i in range(m):
        #     mirror = 2 * c - i
        #     if i < r:
        #         p[i] = min(p[mirror], r - i)
        #     while i + p[i] + 1 < m and i - p[i] - 1 >= 0 and \
        #           t[i + p[i] + 1] == t[i - p[i] - 1]:
        #         p[i] += 1
        #     if i + p[i] > r:
        #         c, r = i, i + p[i]
        # max_len = max(p)
        # center  = p.index(max_len)
        # start   = (center - max_len) // 2
        # return s[start:start + max_len]

        # Approach 2 -- Interval DP
        # # DP State:
        # #       dp[i][j] = True if substring s[i..j] is palindrome
        # # DP Transition:
        # #       dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]
        # # Base Case:
        # #       dp[i][i] = True (single character is always palindrome)
        # #       dp[i][i + 1] = (s[i] == s[i + 1]) (two character substring)
        #
        # n      = len(s)
        # left, right = 0, 0
        # dp     = [[False] * n for _ in range(n)]
        #
        # # Base Case 1: Single Characters
        # for i in range(n):
        #     dp[i][i] = True
        #
        # # Base Case 2: two character substring
        # for i in range(n - 1):
        #     if s[i] == s[i + 1]:
        #         dp[i][i + 1] = True
        #         left = i
        #         right = i + 1
        #
        # # Fill for lengths 3 and above
        # for length in range(3, n + 1):
        #     for i in range(n - length + 1):
        #         j = i + length - 1
        #         if s[i] == s[j] and dp[i + 1][j - 1]:
        #             dp[i][j] = True
        #             left, right = i, j
        # return s[left:right + 1]

        # Approach 1 -- Brute Force
        # result = ""
        # for i in range(len(s)):
        #     for j in range(i + 1, len(s)):
        #         sub = s[i:j + 1]
        #         if sub == sub[::-1] and len(sub) > len(result):
        #             result = sub
        # return result
