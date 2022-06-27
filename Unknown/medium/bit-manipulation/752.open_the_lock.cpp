/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
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
    vector<string> getChildren(string seed)
    {
        vector<string> children;
        children.reserve(8);
        for (int i = 0; i < 4; i++)
        {
            // Positive Turn
            string temp = seed;
            temp[i] = (((seed[i] - '0') + 1) % 10) + '0';
            children.push_back(temp);
            // Negative Turn
            temp[i] = (((seed[i] - '0') + 9) % 10) + '0';
            children.push_back(temp);
        }
        return children;
    }
    int openLock(vector<string> &deadends, string target)
    {
        /* Approach:
        1. BFS
        */

        // If starting seed is in deadends then we can't move
        if (find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1;

        // Our Queue will have the current lock digit & turns
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        // For BFS we need a set, to remember the child we have visited.
        // Also, we never want a child that is in deadends thus, pushing them in set before hand
        unordered_set<string> seen(deadends.begin(), deadends.end());

        while (!q.empty())
        {
            pair<string, int> p = q.front();
            q.pop();
            if (p.first == target)
                // Reached our target return turns
                return p.second;
            // Increment the turn
            p.second++;
            // Get children
            vector<string> children = getChildren(p.first);
            // Now iterate through all children
            for (auto x : children)
            {
                if (seen.find(x) == seen.end())
                { // Haven't seen this children already
                    q.push({x, p.second});
                    seen.insert(x);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
