/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
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

const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        /* Approach:
            1. DFS -- T.C: O(Edges + Vertices)
            2. DFS (Succint) -- Same as above
            3. BFS -- Same as above
        */

        // BFS
        if (!node)
            return NULL;

        // Copy the first node
        Node *copy = new Node(node->val, {});
        // Map it
        map[node] = copy;
        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            for (auto nei : curr->neighbors)
            {
                if (map.find(nei) == map.end())
                {
                    map[nei] = new Node(nei->val, {});
                    q.push(nei);
                }
                map[curr]->neighbors.push_back(map[nei]);
            }
        }
        return copy;

        /* Approach 2 - Succint DFS
        if (!node)
            return NULL;
        // Find in map
        if (map.find(node) == map.end())
        {
            // No present in map, create new node
            map[node] = new Node(node->val, {});
            // Now recursively copy the neighbors
            for (auto nei : node->neighbors)
                map[node]->neighbors.push_back(cloneGraph(nei));
        }
        return map[node];
        */

        /* Approach 1
        // Corner Case
        if (node == NULL)
            return NULL;

        // We will use a node* array to Map Old and New Node
        vector<Node *> map(1000, NULL);

        // Call our DFS function
        return doDFS(node, map);
        */
    }

private:
    unordered_map<Node *, Node *> map;
    /* Approach 1
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
    */
};
// @lc code=end
