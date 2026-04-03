# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        """
        Approach:
        1. Recursive DFS -- T.C: O(M * N), S.C: O(M + N)
             - For each node in root, check if subRoot matches starting from that node.
             - M = nodes in root, N = nodes in subRoot
        2. Serialization -- T.C: O(M + N), S.C: O(M + N)
             - Serialize both trees into strings, then check if subRoot's
               serialization is a substring of root's serialization.
             - Use delimiters to avoid false matches e.g [12] matching [2]
        """

        # Approach 2 -- Serialization
        def serialize(node: Optional[TreeNode]) -> str:
            if not node:
                return ",#"
            return "," + str(node.val) + serialize(node.left) + serialize(node.right)

        return serialize(subRoot) in serialize(root)

        # Approach 1 -- DFS
        # def is_same(p, q):
        #     if not p and not q: return True
        #     if not p or not q:  return False
        #     if p.val != q.val:  return False
        #     return is_same(p.left, q.left) and is_same(p.right, q.right)
        #
        # if not root:
        #     return False
        # if is_same(root, subRoot):
        #     return True
        # return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
