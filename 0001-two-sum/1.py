class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Approach 2: HashMap -- T.C: O(N), S.C: O(N)
        hashmap = {}

        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap:
                return [i, hashmap[complement]]
            hashmap[nums[i]] = i

        return []

        """
        # Approach 1: Brute Force -- T.C: O(N^2), S.C: O(1)
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if target - nums[i] == nums[j]:
                    return [i, j]
        return []
        """
