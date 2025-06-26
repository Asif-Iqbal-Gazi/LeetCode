class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        curr_count, ans = 0, 0
        
        for num in nums:
            if num:
                curr_count += 1
                if curr_count > ans:
                    ans = curr_count
            else:
                curr_count = 0
        return ans
