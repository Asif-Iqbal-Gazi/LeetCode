class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Approach:
        1. Brute Force                     -- T.C: O(N^2), S.C: O(1)
             - For each element, multiply all others.
        2. Prefix + Suffix Arrays          -- T.C: O(N),   S.C: O(N)
             - Build prefix and suffix arrays, multiply at each index.
        3. Prefix + Suffix Space Optimized -- T.C: O(N),   S.C: O(1)
             - Use output array for prefix pass, running suffix for second pass.
        """

        # Approach 3 -- Prefix + Suffix Space Optimized
        n = len(nums)
        ans = [1] * n

        # Pass 1: fill ans with prefix products
        for i in range(1, n):
            ans[i] = ans[i - 1] * nums[i - 1]

        # Pass 2: multiply running suffix into ans
        suffix = 1
        for i in range(n - 1, -1, -1):
            ans[i] *= suffix
            suffix *= nums[i]
        return ans

        # Approach 2 -- Prefix + Suffix Arrays
        # n      = len(nums)
        # prefix = [1] * n
        # suffix = [1] * n
        # for i in range(1, n):
        #     prefix[i] = prefix[i - 1] * nums[i - 1]
        # for i in range(n - 2, -1, -1):
        #     suffix[i] = suffix[i + 1] * nums[i + 1]
        # return [prefix[i] * suffix[i] for i in range(n)]

        # Approach 1 -- Brute Force
        # n   = len(nums)
        # ans = [1] * n
        # for i in range(n):
        #     product = 1
        #     for j in range(n):
        #         if i != j:
        #             product *= nums[j]
        #     ans[i] = product
        # return ans
