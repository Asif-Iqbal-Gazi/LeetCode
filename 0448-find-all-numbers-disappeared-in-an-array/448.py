class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        for num in nums:
            index = abs(num) - 1
            if nums[index] > 0:
                nums[index] *= -1

        return [i + 1 for i, num in enumerate(nums) if num > 0]

