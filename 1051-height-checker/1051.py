class Solution:
    def heightChecker(self, heights: List[int]) -> int:
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
