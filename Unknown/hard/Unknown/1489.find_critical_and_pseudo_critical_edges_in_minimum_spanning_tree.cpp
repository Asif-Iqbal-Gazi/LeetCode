/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 */

// @lc code=start
class DSU {
   private:
    int sz;
    vector<int> root, rank;

   public:
    DSU(int sz) {
        this->sz = sz;
        root.resize(sz);
        rank.resize(sz);
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false;
        if (rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else {
            root[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    void reset() {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
};

class Solution {
   private:
    int N;
    DSU *dsu;
    int edgeCount;
    vector<vector<int>> myEdges;
    int findMSTwithCondition(int avoidMe, bool alreadyPickedOne) {
        // If avoidMe == -1 then find MST for the given edgeList
        // If alreadyPickedOne == true, then our dsu already has that information recorded
        // This, function will try to find the MST with above two condition
        // If Spanning Tree is not possible it will return INT_MAX
        int ans = 0;
        int totalOp = 0;
        if (alreadyPickedOne) totalOp++;
        for (int i = 0; i < edgeCount; i++) {  // O(edgeCount * a(V))
            if (totalOp == N - 1) break;
            if (myEdges[i][3] == avoidMe) continue;
            if (dsu->unionSet(myEdges[i][1], myEdges[i][2])) {
                ans += myEdges[i][0];
                totalOp++;
            }
        }
        // Reset the DSU
        dsu->reset();
        return totalOp == N - 1 ? ans : INT_MAX;
    }

   public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        /* Approach:
            1. Krushkal Algorithm -- T.C: O(E^2 * α(V)), S.C: O(E); V: No. of nodes(n), E: no of edges
                -- Intuition:
                    -- Find the "mst" of the given graph
                    -- Now, find the "curr_mst" if a particular edge is not selected
                    -- If "curr_mst" > "mst" then edge we skipped belongs to critical edge
                    -- If "curr_mst" == "mst" then this edge might be a pseudoCritical edge
                        -- But why "might be" ?? Because, it may happen that this edge will never be part of our MST
                        -- e.g : n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
                            Here, edges[5] = [1,4,6] is never part of a MST (the way are doing the processing, i.e: skipping edge)
                        So, to verify this, we will force this edge to be part of our MST, and calculate the "curr_mst" again
                        If "curr_mst" == "mst" then with certainty we can say this edge belongs to pseudoCritical edge
        */

        // Approach 1 -- Krushkal
        N = n;
        edgeCount = edges.size();
        myEdges.clear();
        myEdges.assign(edgeCount, {});

        // Insert index to the edgeList
        for (int i = 0; i < edgeCount; i++) {
            myEdges[i].push_back(edges[i][2]);
            myEdges[i].push_back(edges[i][0]);
            myEdges[i].push_back(edges[i][1]);
            myEdges[i].push_back(i);
        }
        // Sort myEdges based on weight                             // T.C: O(E log E)
        sort(myEdges.begin(), myEdges.end(), [](auto const &v1, auto const &v2) -> bool { return v1[0] < v2[0]; });
        // Have a new DSU to find the MST of the tree
        dsu = new DSU(N);  // O(n)
        int mst = findMSTwithCondition(-1, false);
        if (mst == INT_MAX) {
            // Spanning Tree Not possible for this graph
            delete dsu;
            return {};
        }

        vector<int> critical;
        vector<int> pseudoCritical;
        for (int i = 0; i < edgeCount; i++) {  // T.C: O(edgeCount^2 * α(V))
            // Find MST by not taking ith edge
            int curr_mst = findMSTwithCondition(i, false);
            if (curr_mst > mst)  // Definitely a critical edge
                critical.push_back(i);
            else if (curr_mst == mst) {  // Might be a pseudoCritical edge
                // Let's calculate MST by taking this edge
                curr_mst = edges[i][2];
                dsu->unionSet(edges[i][0], edges[i][1]);
                curr_mst += findMSTwithCondition(-1, true);
                if (curr_mst == mst) pseudoCritical.push_back(i);  // We are sure this is a pseudoCritical edge
            }
        }

        delete dsu;
        return {critical, pseudoCritical};
    }
};
// @lc code=end
