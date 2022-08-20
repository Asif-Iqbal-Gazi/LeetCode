/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        /* Approach:
            1. DFS -- O(Edges + Vertices)
        */

        // Corner Case
        if (node == NULL)
            return NULL;

        // We will use a node* array to Map Old and New Node
        vector<Node *> map(1000, NULL);

        // Call our DFS function
        return doDFS(node, map);
    }

private:
    Node *doDFS(Node *node, vector<Node *> &map)
    {
        // If already in the map return it
        if (map[node->val])
            return map[node->val];
        // Not in the map, create a new
        Node *copy = new Node(node->val);
        // Put the copy node in the map
        map[node->val] = copy;
        // For all it's neighbors copy as well
        for (auto nei : node->neighbors)
            copy->neighbors.push_back(doDFS(nei, map));
        return copy; // Finally, return the copy
    }
};
// @lc code=end
