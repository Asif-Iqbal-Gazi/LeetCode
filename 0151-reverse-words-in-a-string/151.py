class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split()
        return ' '.join(reversed(words))
        
