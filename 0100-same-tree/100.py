# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        """
        Approach:
        1. Recursive DFS -- T.C: O(N), S.C: O(N)
             - Recursively check if current nodes are equal, then verify
               left and right subtrees match.
        2. Iterative BFS -- T.C: O(N), S.C: O(N)
             - Use a queue to traverse both trees simultaneously,
               comparing nodes level by level.
        """

        # Approach 1 -- Recursive DFS
        # if not p or not q:
        #     return p == q

        # return (
        #     p.val == q.val
        #     and self.isSameTree(p.left, q.left)
        #     and self.isSameTree(p.right, q.right)
        # )

        # Approach 2 -- Iterative BFS
        from collections import deque

        dq = deque([(p, q)])
        while dq:
            np, nq = dq.popleft()
            if not np and not nq:
                continue
            if not np or not nq:
                return False
            if np.val != nq.val:
                return False
            dq.append((np.left, nq.left))
            dq.append((np.right, nq.right))
        return True
