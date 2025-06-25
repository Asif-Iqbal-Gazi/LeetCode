class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        l, r, temp = 0, len(nums) - 1, 0

        while l < r:
            if nums[l] & 1:
                temp = nums[l]
                nums[l] = nums[r]
                nums[r] = temp
                r -= 1
            else:
                l += 1

        return nums
