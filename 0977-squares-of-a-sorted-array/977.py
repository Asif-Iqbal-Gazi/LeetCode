class Solution:
    def sortedSquares(sef, nums: List[int]) -> List[int]:
        l, r = 0, len(nums) -1
        result = [0] * len(nums)
        pos = len(nums) - 1
    
        while l <= r:
            left_sq = nums[l] ** 2
            right_sq = nums[r] ** 2
            if left_sq > right_sq:
                result[pos] = left_sq
                l += 1
            else:
                result[pos] = right_sq
                r -= 1
            pos -= 1
    
        return result
