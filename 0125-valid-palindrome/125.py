class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        Approach:
        1. Two Pointers -- T.C: O(N), S.C: O(1)
             - Use two pointers, skip non-alphanumeric, compare lowercase.
        2. String Filtering -- T.C: O(N), S.C: O(N)
             - Build filtered lowercase string and compare with reverse.
        """

        # Approach 1 -- Two Pointers
        l, r = 0, len(s) - 1

        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1

            if s[l].lower() != s[r].lower():
                return False

            l += 1
            r -= 1

        return True

        # Approach 2 -- String Filtering
        # t = ''.join(c.lower() for c in s if c.isalnum())
        # return t == t[::-1]
