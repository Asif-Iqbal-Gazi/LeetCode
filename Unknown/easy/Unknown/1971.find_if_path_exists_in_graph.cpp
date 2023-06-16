/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class UnionFind
{
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int sz)
    {
        root.resize(sz);
        rank.resize(sz);
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }

    bool unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false;
        if (rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else
        {
            root[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Solution
{
private:
    /*
    bool doDFS(int src, int des, vector<int> &visited, vector<int> adj[])
    {
        // Mark as visited
        visited[src] = 1;

        // Check all it's neighbour
        for (auto nei : adj[src])
        {
            if (nei == des) // Reached destination, return true;
                return true;
            if (visited[nei] == 0 && doDFS(nei, des, visited, adj))
                return true; // Unvisited neighbour, call dfs from here,
                             // return true to avoid further recursion
        }
        return false;
    }
    */

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        /* Approach:
            1. DFS -- T.C: O(n + m), S.C: O(n)
            2. BFS -- T.C: O(n + m), S.C: O(n)
            3. UnionFind -- T.C: O(ma(N)), S.C: O(n)
        */

        // Approach 3
        // Edge Case
        if (source == destination)
            return true;

        UnionFind *uf = new UnionFind(n);
        for (auto e : edges)
            uf->unionSet(e[0], e[1]);

        return uf->find(source) == uf->find(destination);

        /* Approach 2
        // Edge Case
        if (source == destination)
            return true;

        vector<int> adj[n];
        // Building the adjacency list
        for (auto e : edges)
        { // T.C: O(m)
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<int> visited(n, 0); // T.C: O(n)

        q.push(source);
        visited[source] = 1;

        while (!q.empty())
        { // T.C: O(n + m)
            int curr = q.front();
            q.pop();
            for (auto nei : adj[curr])
            {
                if (nei == destination)
                    return true;
                if (visited[nei] == 0)
                {
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }
        return false;
        */

        /* Approach 1
        // Edge Case
        if (source == destination)
            return true;

        vector<int> adj[n];
        // Building the adjacency list
        for (auto e : edges)
        { // T.C: O(m)
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0); // T.C: O(n)

        return doDFS(source, destination, visited, adj); // T.C: O(n + m)
        */
    }
};
// @lc code=end
