class Solution:
    def fib(self, n: int) -> int:
        if (n <= 1):
            return n

        prev, prev2prev = 1, 0

        for _ in range(2, n + 1):
            curr = prev + prev2prev
            prev2prev = prev
            prev = curr

        return prev
        
