# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def build_all_trees(self, start: int, end: int) -> List[Optional[TreeNode]]:
        if start > end:
            return [None]
        
        all_trees = []
        for root_val in range(start, end + 1):
            left_trees = self.build_all_trees(start, root_val - 1)
            right_trees = self.build_all_trees(root_val + 1, end)

            for l in left_trees:
                for r in right_trees:
                    root = TreeNode(root_val)
                    root.left = l
                    root.right = r
                    all_trees.append(root)

        return all_trees

    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        """
        Approach:
            1. [Recursion] -- T.C: O(n * C(n)), S.C: O(n * C(n)); C(n): nth Catalan Number
                - Each number in [1..n] is choosen as root, and all combinations of left/right subtrees are built recursively.
        """

        return self.build_all_trees(1, n)
        
