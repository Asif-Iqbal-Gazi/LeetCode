class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Binary Exponentiation -- T.C: O(log N),  S.C: O(1)
        if n < 0:
            x = 1 / x
            n = -n

        res = 1.0
        while n:
            if n % 2:
                res *= x
            x *= x
            n //= 2

        return res
