class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count = 0
        for num in nums:
            digit_count = 0
            while num:
                digit_count += 1
                num //= 10
            if digit_count % 2 == 0:
                count += 1
        return count
