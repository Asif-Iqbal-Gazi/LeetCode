class Solution {
  private:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false; // cycle detected
        // union by rank
        if (rank_[px] < rank_[py])
            parent[px] = py;
        else if (rank_[px] > rank_[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank_[px]++;
        }
        return true;
    }

  public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
         * Approach:
         * 1. DFS        -- T.C: O(V + E),    S.C: O(V + E)
         *      - Build adjacency list, run DFS tracking visited and parent.
         *        Cycle = visited non-parent node. Check all visited for connectivity.
         * 2. BFS        -- T.C: O(V + E),    S.C: O(V + E)
         *      - Same as DFS but level by level using a queue.
         * 3. Union Find -- T.C: O(E · α(V)), S.C: O(V)
         *      - For each edge, if both nodes share a root → cycle.
         *        After all edges, verify exactly n - 1 edges exist.
         */

        // Approach 3 -- Union Find
        if (edges.size() != n - 1)
            return false;
        parent.resize(n);
        rank_.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto& edge : edges) {
            if (!unite(edge[0], edge[1]))
                return false;
        }
        return true;

        /* Approach 1 -- DFS
        if (edges.size() != n - 1)
            return false;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        stack<pair<int, int>> st; // {node, parent}
        st.push({0, -1});
        while (!st.empty()) {
            auto [node, par] = st.top();
            st.pop();
            visited[node] = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor])
                    st.push({neighbor, node});
                else if (neighbor != par)
                    return false;
            }
        }
        return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
        */

        /* Approach 2 -- BFS
        if (edges.size() != n - 1)
            return false;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>    visited(n, false);
        queue<pair<int,int>> q; // {node, parent}
        q.push({0, -1});
        while (!q.empty()) {
            auto [node, par] = q.front();
            q.pop();
            visited[node] = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor])
                    q.push({neighbor, node});
                else if (neighbor != par)
                    return false;
            }
        }
        return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
        */
    }
};
