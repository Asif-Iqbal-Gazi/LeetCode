class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        left, running_sum = (0, 0)
        
        ans = n + 1
        for right in range(n):
            running_sum += nums[right]
            while running_sum >= target:
                ans = min(ans, right - left + 1)
                running_sum -= nums[left]
                left += 1

        return 0 if ans == n + 1 else ans
