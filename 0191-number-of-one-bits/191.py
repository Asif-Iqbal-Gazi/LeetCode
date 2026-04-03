class Solution:
    def hammingWeight(self, n: int) -> int:
        """
        Approach:
        1. Bit Shift -- T.C: O(1), S.C: O(1)
             - Check each of the 32 bits one at a time by extracting the
               LSB with n & 1, then right shifting n by 1.
        2. Brian Kernighan's Algorithm -- T.C: O(k), S.C: O(1)
             - n & (n - 1) clears the lowest set bit of n.
               Repeat until n is zero, counting iterations.
               Only iterates as many times as there are set bits.
               k = number of set bits.
        """
        # Approach 2 -- Brian Kernighan
        count = 0
        while n:
            n &= n - 1
            count += 1
        return count

        # Approach 1 -- Bit Shift
        # count = 0
        # while n:
        #     count += n & 1
        #     n >>= 1
        # return count
