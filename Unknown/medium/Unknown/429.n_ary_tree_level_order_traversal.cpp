/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        /* Approach:
            1. BFS -- T.C: O(V + E), S.C: O(V)
        */

        // Approach
        if (!root)
            return {};

        vector<vector<int>> ans;
        queue<Node *> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();

            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                Node *curr = nodeQueue.front();
                nodeQueue.pop();
                tmp.push_back(curr->val);
                for (auto child : curr->children)
                {
                    if (child)
                        nodeQueue.push(child);
                }
            }
            if (tmp.size() > 0)
                ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end
