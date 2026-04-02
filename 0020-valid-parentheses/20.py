class Solution:
    def isValid(self, s: str) -> bool:
        # Approach: Stack -- T.C: O(n), S.C: O(n)

        n = len(s)

        # Optimization: Exit early
        if n % 2 == 1:
            return False

        stack = []
        for c in s:
            if c == "(":
                stack.append(")")
            elif c == "{":
                stack.append("}")
            elif c == "[":
                stack.append("]")
            else:
                if len(stack) == 0 or stack[-1] != c:
                    return False
                else:
                    stack.pop()
        return not stack
