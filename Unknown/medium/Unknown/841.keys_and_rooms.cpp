/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        /* Approach:
            1. BFS -- T.C:O(sum(rooms[i].size())), S.C:O(sum(rooms[i].size()))
        */

        int n = rooms.size();
        // We need a visited array to keep track of our visit to a room
        vector<int> visited(n, -1);
        // We need a variable to keep track of non-visited room
        int nonVisited = n;

        // We will need a queue for our BFS algorithm
        queue<int> q;
        // rooms[0] is unlocked so we push it into our queue and mark it as visited initially
        visited[0] = 0;
        q.push(0);
        nonVisited--;

        while (!q.empty())
        {
            // Get the curr room
            int curr = q.front();
            q.pop();
            // For all key(s) found in the room and not already visited, mark visited and add to queue for visit
            for (auto next : rooms[curr])
            {
                if (visited[next] == -1)
                {
                    // Found a room not visited
                    visited[next] = 0;
                    q.push(next);
                    nonVisited--;
                }
            }
        }

        /* Now iterate over visited array and check if any room is not visitd
        for (auto r : visited)
            if (r == -1)
                return false;
        return true;
        */
        return nonVisited == 0 ? true : false;
    }
};
// @lc code=end
