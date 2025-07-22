class Solution:
    def _reverse(self, nums: List[int], start: int, end: int) -> None:
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n

        self._reverse(nums, 0, n - k - 1)
        self._reverse(nums, n - k, n - 1)
        self._reverse(nums, 0, n - 1)
