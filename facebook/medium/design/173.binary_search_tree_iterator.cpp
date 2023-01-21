/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

// @lc code=start
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
class BSTIterator
{
private:
    // Approach 2
    stack<TreeNode *> s;
    void inOrderLeft(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }

    /* Approach 1
    int size;
    int currPos;
    vector<int> ds;
    void doInOrderTraversal(TreeNode *root, vector<int> &ds)
    {
        if (!root)
            return;
        doInOrderTraversal(root->left, ds);
        ds.push_back(root->val);
        doInOrderTraversal(root->right, ds);
    }
    */

public:
    /* Approach:
        1. Flatten to Sorted Array
            T.C : O(1) for next() and hasNext()
                  O(N) for initialization
            S.C : O(1)
        2. Controlled Recursion with Stack
            T.C: O(1) hasNext()
                 O(1) amortized for next()
            S.C: O(h)
    */

    BSTIterator(TreeNode *root)
    {
        inOrderLeft(root);
    }

    int next()
    {
        TreeNode *curr = s.top();
        s.pop();

        inOrderLeft(curr->right);
        return curr->val;
    }

    bool hasNext()
    {
        return s.size();
    }

    /* Approach 1
    BSTIterator(TreeNode *root)
    {
        doInOrderTraversal(root, ds);
        size = ds.size();
        currPos = -1;
    }

    int next()
    {
        currPos++;
        return ds[currPos];
    }

    bool hasNext()
    {
        return currPos < (size - 1);
    }
    */
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
