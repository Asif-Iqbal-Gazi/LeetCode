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

class Solution {
  private:
    unordered_map<Node *, Node *> cloneMap;

    Node *dfs(Node *node) {
        if (!node)
            return nullptr;
        if (cloneMap.count(node))
            return cloneMap[node];
        Node *clone    = new Node(node->val);
        cloneMap[node] = clone;
        for (Node *neighbor : node->neighbors) clone->neighbors.push_back(dfs(neighbor));
        return clone;
    }

  public:
    Node *cloneGraph(Node *node) {
        /*
         * Approach:
         * 1. DFS + Hash Map -- T.C: O(V + E), S.C: O(V)
         *      - Recursively clone each node. Use a hash map to track already
         *        cloned nodes to avoid infinite loops in cyclic graphs.
         * 2. BFS + Hash Map -- T.C: O(V + E), S.C: O(V)
         *      - Clone nodes level by level using a queue.
         */

        // Approach 1 -- DFS
        return dfs(node);

        /* Approach 2 -- BFS
        if (!node)
            return nullptr;
        unordered_map<Node *, Node *> cloneMap;
        queue<Node *>                 q;
        cloneMap[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            for (Node *neighbor : curr->neighbors) {
                if (!cloneMap.count(neighbor)) {
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
            }
        }
        return cloneMap[node];
        */
    }
};
