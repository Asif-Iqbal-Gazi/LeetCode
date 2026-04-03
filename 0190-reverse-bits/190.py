class Solution:
    def reverseBits(self, n: int) -> int:
        # Approach:
        #   Bit Manipulation -- T.C: O(1), S.C: O(1)

        res = 0
        for i in range(32):
            bit = (n >> i) & 1
            res |= bit << (31 - i)
        return res
