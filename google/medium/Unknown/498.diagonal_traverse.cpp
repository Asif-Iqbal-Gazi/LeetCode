/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
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
    vector<int> findDiagonalOrder(vector<vector<int> > &mat)
    {
        /*
        Approach:
        1. Observe, with respect 0-based row and column index, we got up when (row+col) is even and down when (row+col) is odd.
        2. While going up row decreases and col increases, similarly, while downward row increases and col decreases.
        3. Edge case, during upward movement: row can become 0 or col can reach length, in these cases increase col and increase row respectively.
           Similarly, during downward movement: col can become zero or row can reach length, in these cases increase row and increase column respectively.
        */

        int m = mat.size(), n = mat[0].size(), r = 0, c = 0;
        // Our result array
        vector<int> result(m * n, 0);
        for (int i = 0; i < result.size(); i++)
        {
            result[i] = mat[r][c];
            // Upward
            if ((r + c) % 2 == 0)
            {
                // During upward we will reach c==n-1 condition first before r==0, hence check needs to be done accordingly
                if (c == n - 1)
                    r++;
                else if (r == 0)
                    c++;
                else
                {
                    r--;
                    c++;
                }
            }
            // Downward
            else
            {
                // During downward we will reach r==m-1 condition first before c==0, hence check needs to be done accordingly
                if (r == m - 1)
                    c++;
                else if (c == 0)
                    r++;
                else
                {
                    r++;
                    c--;
                }
            }
        }
        return result;
    }
};
// @lc code=end
