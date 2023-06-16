/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        /* Approach:
            1. BFS -- T.C: O(NE), S.C: O(NE)
            2. DIJKSTRA's Algo -- T.C:
        */

        // Approach 1
        vector<pair<int, int>> adj[n + 1];
        // Create the adjacency list
        for (auto e : times)
        { // T.C: O(E)
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> travelTime(n + 1, INT_MAX);
        travelTime[k] = 0;

        queue<int> q;

        q.push(k);

        while (!q.empty())
        { // T.C: O(NE)
            int node = q.front();
            q.pop();

            for (auto nei : adj[node])
            {
                int curr_delay = travelTime[node] + nei.second;
                if (curr_delay < travelTime[nei.first])
                {
                    travelTime[nei.first] = curr_delay;
                    q.push(nei.first);
                }
            }
        }

        int ans = 0;

        for (int i = 1; i < n + 1; i++)
        { // T.C: O(N)
            if (i == k)
                continue;
            if (travelTime[i] == INT_MAX)
                return -1;
            if (ans < travelTime[i])
                ans = travelTime[i];
        }

        return ans;
    }
};
// @lc code=end
