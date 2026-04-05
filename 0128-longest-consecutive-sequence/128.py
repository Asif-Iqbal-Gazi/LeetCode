class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        Approach:
        1. Hash Set -- T.C: O(N), S.C: O(N)
             - Use set, start only from sequence starts.
        2. Sorting -- T.C: O(N log N), S.C: O(1)
             - Sort and count consecutive elements.
        """

        # Approach 1 -- Hash Set
        s = set(nums)
        longest = 0

        for num in s:
            if num - 1 not in s:
                curr = num
                streak = 1

                while curr + 1 in s:
                    curr += 1
                    streak += 1

                longest = max(longest, streak)

        return longest

        # Approach 2 -- Sorting
        # if not nums:
        #     return 0
        # nums.sort()
        # longest = curr = 1
        # for i in range(1, len(nums)):
        #     if nums[i] == nums[i-1]:
        #         continue
        #     elif nums[i] == nums[i-1] + 1:
        #         curr += 1
        #     else:
        #         longest = max(longest, curr)
        #         curr = 1
        # return max(longest, curr)
