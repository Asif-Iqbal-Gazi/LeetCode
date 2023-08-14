/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class UnionFind {
   private:
    vector<int> root;
    vector<int> rank;

   public:
    UnionFind(int sz) {
        root.resize(sz);
        rank.resize(sz);
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (root[x] == x)
            return x;
        return root[x] = find(root[x]);
    }

    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[x] > rank[y])
                root[rootY] = rootX;
            else if (rank[x] < rank[y])
                root[rootX] = rootY;
            else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
   private:
    /* doDFS helper function
    void doDFS(int i, vector<int> &visited, vector<vector<int>> &graph) {
        int n = graph.size();

        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                doDFS(j, visited, graph);
            }
        }
    }
    */
   public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        /* Approach:
            1. DFS -- T.C: O(n^2), S.C: O(n)
            2. BFS -- T.C: O(n^2), S.C: O(n)
            3. UnionFind -- T.C: O(n^2), S.C: O(n)
        */

        // Approach 3 -- Disjoint Set
        int n = isConnected.size();

        UnionFind uf(n);
        int ans = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] && uf.unionSet(i, j))
                    ans--;
            }
        }
        return ans;

        /* Approach 2 -- BFS
        int ans = 0;
        int n = isConnected.size();

        queue<int> q;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans++;
                visited[i] = 1;
                q.push(i);

                while (!q.empty()) {
                    int nei = q.front();
                    q.pop();
                    for (int j = 0; j < n; j++) {
                        if (isConnected[nei][j] == 1 && visited[j] == 0) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
        */

        /* Approach 1 -- DFS
        int ans = 0;
        int n = isConnected.size();

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans++;
                visited[i] = 1;
                doDFS(i, visited, isConnected);
            }
        }

        return ans;
        */
    }
};
// @lc code=end
