class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        # Approach 2: Counting Sort
        #               T.C: O(N), S.C: O(1)
        count = [0] * 101
        for h in heights:
            count[h] += 1

        res = 0
        curr_height = 1
        for h in heights:
            while count[curr_height] == 0:
                curr_height += 1
            if h != curr_height:
                res += 1
            count[curr_height] -= 1
        return res

        """
        # Appraoch 1: Sorting
        #           T.C: O(n log n), S.C: O(n)
        sorted_heights = sorted(heights)

        res = 0
        for i in range(0, len(heights)):
            if sorted_heights[i] != heights[i]:
                res += 1
        return res
        """
