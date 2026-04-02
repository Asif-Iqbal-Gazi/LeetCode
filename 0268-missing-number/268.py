class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # Approach 2: XoR Technique -- T.C: O(N), S.C: O(1)
        missing = len(nums)

        for i, num in enumerate(nums):
            missing ^= i ^ num

        return missing

        """
        # Appraoch 1: Math Algebra -- T.C: O(N), S.C: O(1)

        n = len(nums)
        total_sum = (n * (n + 1)) >> 1

        for num in nums:
            total_sum -= num

        return total_sum
        """
