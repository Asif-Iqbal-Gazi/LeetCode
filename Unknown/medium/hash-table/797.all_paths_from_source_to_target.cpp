/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution
{
private:
    void doDFS(int curr, vector<int> &path, vector<vector<int>> &graph, vector<vector<int>> &ans)
    {
        if (curr == graph.size() - 1)
        {
            ans.push_back(path);
            return;
        }

        for (auto nei : graph[curr])
        {
            path.push_back(nei);
            doDFS(nei, path, graph, ans);
            path.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        /* Approach:
            1. DFS with BackTracking -- T.C: O(n*2^n), S.C: O(n)
            2. BFS with BackTracking -- T.C: O(n*2^n), S.C: O(n)
        */

        // Approach 2
        int n = graph.size();

        vector<vector<int>> ans;
        vector<int> visited(n, 0);
        queue<vector<int>> graphQueue;

        graphQueue.push({0});
        visited[0] = 1;

        while (!graphQueue.empty())
        {
            vector<int> currPath = graphQueue.front();
            graphQueue.pop();
            int lastNode = currPath.back();

            for (auto nei : graph[lastNode])
            {
                if (nei == n - 1)
                {
                    currPath.push_back(nei);
                    ans.push_back(currPath);
                    currPath.pop_back();
                }
                else if (visited[nei] == 0)
                {
                    visited[nei] == 1;
                    currPath.push_back(nei);
                    graphQueue.push(currPath);
                    currPath.pop_back();
                }
            }
        }

        return ans;

        /* Approach 1
        int n = graph.size();
        vector<int> path;
        path.push_back(0);
        vector<vector<int>> ans;

        doDFS(0, path, graph, ans); // T.C: O(n!)

        return ans;
        */
    }
};
// @lc code=end
