class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix_len = len(strs[0])
        
        for i in range(1, len(strs)):
            j = 0
            while j < prefix_len and j < len(strs[i]) and strs[i][j] == strs[0][j]:
                j += 1
            prefix_len = j
            if prefix_len == 0:
                break
                
        return strs[0][:prefix_len]

