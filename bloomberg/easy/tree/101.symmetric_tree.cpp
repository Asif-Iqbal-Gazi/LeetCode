/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isMirror(TreeNode *n1, TreeNode *n2)
    {
        if (n1 == NULL && n2 == NULL)
            return true;
        if (n1 == NULL || n2 == NULL)
            return false;
        return (n1->val == n2->val) &&
               isMirror(n1->left, n2->right) &&
               isMirror(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        /* Approach:
            1. Using BFS -- T.C: O(N), S.C: O(width of the tree)
                Idea is to first push the left and right child of the root in the queue,
                Then after popping two nodes at a time we push left child of first node and right child of the second node.
                Then after popping we check if the value of the popped nodes are same.
            2. Recursion -- T.C: O(N), S.C: O(N)

        */

        /* Approach 1
        if (!root)
            return true;
        queue<TreeNode *> q;
        // Push root's left and right child into the queue
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *node1 = q.front();
            q.pop();
            TreeNode *node2 = q.front();
            q.pop();
            // If both are NULL skip checks below and continue
            if (node1 == NULL && node2 == NULL)
                continue;
            // If one of them is NULL return false
            if (node1 == NULL || node2 == NULL)
                return false;
            if (node1->val != node2->val)
                return false;

            // If we so far then push the next level children
            q.push(node1->left);
            q.push(node2->right); // Obbserve, we are pushing right child as we have pushed left child for previous node
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
        */

        // Approach 2 -- Recursion

        if (!root)
            return true;
        return isMirror(root, root);
    }
};
// @lc code=end
