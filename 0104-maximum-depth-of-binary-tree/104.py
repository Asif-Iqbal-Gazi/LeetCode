# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        Approach:
        1. Recursive DFS -- T.C: O(N), S.C: O(N)
             - Depth at current node is 1 + max(left, right).
               Base case: null node returns 0.
        2. Iterative BFS -- T.C: O(N), S.C: O(N)
             - Traverse level by level, incrementing depth counter
               for each level processed.
        """

        # Approach 1 -- Recursive DFS
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

        # Approach 2 -- Iterative BFS
        # from collections import deque
        # if not root:
        #     return 0
        # dq    = deque([root])
        # depth = 0
        # while dq:
        #     for _ in range(len(dq)):
        #         node = dq.popleft()
        #         if node.left:  dq.append(node.left)
        #         if node.right: dq.append(node.right)
        #     depth += 1
        # return depth
