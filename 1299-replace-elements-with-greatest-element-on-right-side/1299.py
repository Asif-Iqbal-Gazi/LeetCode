class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        right_max = -1
        r = len(arr) - 1

        while r >= 0:
            curr = arr[r]
            arr[r] = right_max
            if curr > right_max:
                right_max = curr
            r -= 1

        return arr
