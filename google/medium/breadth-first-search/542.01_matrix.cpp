/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
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
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        /* Approach:
            1. BFS -- T.C: O(R.C), S.C: O(R.C)
        */

        int row = mat.size();
        int col = mat[0].size();
        // We create a row*col size distance matrix, initially we set all values to MAX_INT
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        // We need a queue for our BFS algorithm
        queue<pair<int, int>> q;

        // For all elements in our original matrix with value as zero,
        // We will udpate their distance in dist matrix as zero and push them in queue.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Array to determine neighbors
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS loop
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            // Pop from queue
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nR = curr.first + dir[i][0];
                int nC = curr.second + dir[i][1];
                // Check if neighbor coordinate is valid
                if (nR >= 0 && nC >= 0 &&
                    nR < row && nC < col &&
                    dist[nR][nC] > dist[curr.first][curr.second] + 1)
                {
                    // Update the distance of the neighbor.
                    dist[nR][nC] = dist[curr.first][curr.second] + 1;
                    // Push the neighbor coordinate into the queue as well.
                    q.push({nR, nC});
                }
            }
        }
        // Return dist;
        return dist;
    }
};
// @lc code=end
