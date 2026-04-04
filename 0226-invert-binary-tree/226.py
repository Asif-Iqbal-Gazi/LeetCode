class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Approach:
        1. Recursive DFS -- T.C: O(N), S.C: O(N)
             - Recursively invert left and right subtrees, then swap them.
        2. Iterative BFS -- T.C: O(N), S.C: O(N)
             - Use a queue to traverse level by level, swapping children at each node.
        """

        # Approach 1 -- Recursive DFS
        if not root:
            return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root

        # Approach 2 -- Iterative BFS
        # from collections import deque
        # if not root:
        #     return None
        # q = deque([root])
        # while q:
        #     node = q.popleft()
        #     node.left, node.right = node.right, node.left
        #     if node.left:  q.append(node.left)
        #     if node.right: q.append(node.right)
        # return root
