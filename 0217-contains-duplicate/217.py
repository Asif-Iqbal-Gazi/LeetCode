class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        Approach:
        1. Brute Force -- T.C: O(N^2),     S.C: O(1)
             - For each element, check all subsequent elements for a duplicate.
        2. Sorting     -- T.C: O(N log N), S.C: O(1)
             - Sort the array. Duplicates will be adjacent.
        3. Hash Set    -- T.C: O(N),       S.C: O(N)
             - Insert each element into a hash set.
               If already present, a duplicate is found.
        """

        # Approach 3 -- Hash Set
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False

        # Approach 2 -- Sorting
        # nums.sort()
        # for i in range(1, len(nums)):
        #     if nums[i] == nums[i - 1]:
        #         return True
        # return False

        # Approach 1 -- Brute Force
        # for i in range(len(nums)):
        #     for j in range(i + 1, len(nums)):
        #         if nums[i] == nums[j]:
        #             return True
        # return False
