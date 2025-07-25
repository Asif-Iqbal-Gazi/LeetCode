class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n

        prev, pre2prev = 2, 1
        for _ in range(3, n + 1):
            curr = prev + pre2prev
            pre2prev = prev
            prev = curr

        return prev
        
