/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
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
    int numIslands(vector<vector<char>> &grid)
    {
        /* Approach:
        1. BFS
            Using two loops start traversing the grid.
            When a '1' is encountered, increment 'ans' and using BFS discover the complete islands
            i.e if there is another island connecting to it mark is seen (By changing it's value to something other than '1')
        2. DFS
        */

        // Approach 2 -- DFS
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        stack<pair<int, int>> st;
        vector<pair<int, int>> direction = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == '1')
                {
                    ans++;
                    st.push({r, c});
                    while (!st.empty())
                    {
                        pair<int, int> p = st.top();
                        st.pop();
                        for (auto x : direction)
                        {
                            int nR = p.first + x.first;
                            int nC = p.second + x.second;
                            if (nR >= 0 && nR < row &&
                                nC >= 0 && nC < col &&
                                grid[nR][nC] == '1')
                            {
                                grid[nR][nC] = '2';
                                st.push({nR, nC});
                            }
                        }
                    }
                }
            }
        }
        return ans;

        /* BFS
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> direction = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == '1')
                {
                    ans++;
                    q.push({r, c});
                    grid[r][c] = '2';
                    while (!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (auto x : direction)
                        {
                            int nR = p.first + x.first;
                            int nC = p.second + x.second;

                            if (nR >= 0 && nR < row &&
                                nC >= 0 && nC < col &&
                                grid[nR][nC] == '1')
                            {
                                grid[nR][nC] = '2';
                                q.push({nR, nC});
                            }
                        }
                    }
                }
            }
        }
        return ans;
        */
    }
};
// @lc code=end
