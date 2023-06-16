/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
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
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        /* Approach:
            1. MST (Krushkal's Algorithm) -- T.C: O(n^2logn), S.C: O(n^2)
            2. MST (Prim's Algorithm) -- T.C: O(n^2logn), S.C: O(n^2)
        */

        // Approach 2
        int n = points.size();
        // Edge Case
        if (n == 1)
            return 0;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        vector<pair<int, int>> adj[n];

        // Create weighted adjacency list
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({wt, j});
                adj[j].push_back({wt, i});
            }
        }

        vector<int> visited(n, 0);

        pq.push({0, 0});
        int op = 0;
        int ans = 0;

        while (!pq.empty())
        {
            if (op == n)
                break;
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = 1;
            ans += wt;
            op++;

            for (auto nei : adj[node])
            {
                if (visited[nei.second] == 0)
                {
                    pq.push(nei);
                }
            }
        }

        return ans;

        /* Approach 1
        int n = points.size();
        // Edge Case
        if (n == 1)
            return 0;

        vector<pair<int, pair<int, int>>> adj;

        // Create the weighted adjacency list
        for (int i = 0; i < n - 1; i++)
        { // T.C: O(n^2)
            for (int j = i + 1; j < n; j++)
            {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({w, {i, j}});
            }
        }

        // Sort the adjacency list
        sort(adj.begin(), adj.end()); // T.C: O(nlogn)

        int op = 0;
        int ans = 0;

        UnionFind *uf = new UnionFind(n); // T.C: O(n)

        for (auto e : adj)
        {
            // Break early, if we have n - 1 edges already
            if (op == n - 1)
                break;
            if (uf->unionSet(e.second.first, e.second.second))
            {
                op++;
                ans += e.first; // T.C: O(na(n))
            }
        }

        return ans;
        */
    }
};
// @lc code=end
