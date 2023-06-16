/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class UninonFind
{
private:
    int count;
    vector<int> root;
    vector<int> rank;

public:
    UninonFind(int sz)
    {
        count = sz;
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

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    int noOfProvinces()
    {
        return count;
        /*
        unordered_set<int> unique;
        for (int i = 0; i < n; i++)
        {
            find(i); // <-- This will force path compression
            unique.insert(root[i]);
        }
        return unique.size();
        */
    }
};
class Solution
{
private:
    /*
    void doDFS(int i, vector<int> &visited, vector<vector<int>> &graph)
    {
        int n = graph.size();

        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1 && visited[j] == 0)
            {
                // Mark this node visited
                visited[j] = 1;
                // Call dfs on this node
                doDFS(j, visited, graph);
            }
        }
    }
    */

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        /* Approach:
            1. DFS -- T.C: O(n^2), S.C: O(n)
            2. BFS -- T.C: O(n^2), S.C: O(n)
            3. UnionFind -- T.C: O(N), S.C: O(n)
        */

        // Approach 3
        int n = isConnected.size();
        UninonFind uf(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && !uf.isConnected(i, j))
                    uf.unionSet(i, j);
            }
        }

        return uf.noOfProvinces();

        /* Approach 2
        int ans = 0;
        int n = isConnected.size();

        queue<int> q;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                ans++;
                q.push(i);
                visited[i] = 1;

                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (int j = 0; j < n; j++)
                    {
                        if (isConnected[u][j] == 1 && visited[j] == 0)
                        {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
        */

        /* Approach 1
        int ans = 0;
        int n = isConnected.size();

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            // If not visited doDFS
            if (visited[i] == 0)
            {
                visited[i] = 1;
                ans++;
                doDFS(i, visited, isConnected);
            }
        }
        return ans;
        */
    }
};
// @lc code=end
