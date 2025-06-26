class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left, max_len, zero_count = 0, 0, 0

        for num in nums:
            if num == 0:
                zero_count += 1
            if zero_count > 1:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1

        return len(nums) - left
