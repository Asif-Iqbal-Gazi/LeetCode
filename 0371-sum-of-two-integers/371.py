# NOTE: Python integers are arbitrary precision -- negative numbers don't
# have a fixed 32-bit two's complement representation. We must mask to 32
# bits manually to simulate overflow behavior.
class Solution:
    def getSum(self, a: int, b: int) -> int:
        """
        Approach:
        1. Iterative -- T.C: O(1), S.C: O(1)
             - XOR gives sum without carry.
               AND shifted left gives carry.
               Mask to 32 bits to simulate fixed-width integers.
        """

        # Approach 1 -- Iterative
        MASK = 0xFFFFFFFF  # 32-bit mask
        MAX = 0x7FFFFFFF  # max positive 32-bit int

        while b != 0:
            carry = ((a & b) << 1) & MASK
            a = (a ^ b) & MASK
            b = carry

        # If a > MAX, it's a negative number in two's complement
        return a if a <= MAX else ~(a ^ MASK)
