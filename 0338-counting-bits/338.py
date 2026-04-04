class Solution:
    def countBits(self, n: int) -> List[int]:
        """
        Approach:
        1. Bit Manipulation (Brian Kernighan) -- T.C: O(N log N), S.C: O(1)
             - For each number i, count set bits using i & (i - 1).
        2. Dynamic Programming              -- T.C: O(N),       S.C: O(1)
             - ans[i] = ans[i >> 1] + (i & 1)
             - i >> 1 drops the last bit, its count is already computed.
             - i & 1 adds 1 if i is odd, 0 if even.
        """

        # Approach 2 -- DP
        ans = [0] * (n + 1)
        for i in range(1, n + 1):
            ans[i] = ans[i >> 1] + (i & 1)
        return ans

        # Approach 1 -- Brian Kernighan
        # ans = [0] * (n + 1)
        # for i in range(1, n + 1):
        #     count = 0
        #     x     = i
        #     while x:
        #         x &= (x - 1)
        #         count += 1
        #     ans[i] = count
        # return ans
