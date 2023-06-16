/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        /* Approach:
            1. Levelwise BFS -- T.C: O(V + E * K), S.C: O(V + E * K)
            2. Bellman Ford -- T.C: O(V + K * (E + V)), S.C: O(V)
        */

        // Approach 2
        vector<int> prevCost(n + 1, 1e9); // T.C: O(V)

        prevCost[src] = 0;

        for (int i = 0; i <= k; i++)
        {                                   // T.C: O(K * (V + E))
            vector<int> currCost(prevCost); // T.C: O(V)
            for (auto flight : flights)
            { // T.C: O(E)
                if (prevCost[flight[0]] != 1e9)
                {
                    currCost[flight[1]] = min(currCost[flight[1]], prevCost[flight[0]] + flight[2]);
                }
            }
            prevCost = currCost; // T.C: O(V)
        }

        return prevCost[dst] == 1e9 ? -1 : prevCost[dst];

        /* Approach 1
        vector<pair<int, int>> adj[n];

        for (auto flight : flights)
        { // O(n^2) or O(E)
            int cost = flight[2];
            int adjNode = flight[1];
            int currNode = flight[0];
            adj[currNode].push_back({cost, adjNode});
        }

        queue<pair<int, int>> q;
        vector<int> cost(n + 1, 1e9); // O(V)
        q.push({0, src});

        int level = 0;
        while (!q.empty() && level <= k)
        { // O(n^3) or O(E * K)
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();
                int currCost = it.first;
                int currNode = it.second;
                for (auto nei : adj[currNode])
                {
                    int tCost = nei.first;
                    int adjNode = nei.second;
                    if (cost[adjNode] > currCost + tCost)
                    {
                        cost[adjNode] = currCost + tCost;
                        q.push({cost[adjNode], adjNode});
                    }
                }
            }
            level++;
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];
        */
    }
};
// @lc code=end
