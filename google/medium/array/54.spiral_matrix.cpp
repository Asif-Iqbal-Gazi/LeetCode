/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
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
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        /*
        Approah:
        1. Observe, how we traverse from right -> down -> left ->up and then repeat it.
        2. Now, during our traversal again at right we ignore previous elements (c==n-1) and go down, to track this use variable right = n-1, down = m-1, left = 0, up = 0 initially and then keep on decrementing them once we change our traversal direction.
        */

        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1, right = n - 1, left = 0, direction = 0;
        vector<int> result(m * n, 0);
        int index = 0;
        while (left <= right && up <= down)
        {
            // Traverse right
            if (direction == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    result[index++] = matrix[up][i];
                }
                // Done traversing right.
                direction = 1;
                up++;
            }
            // Traverse down
            else if (direction == 1)
            {
                for (int i = up; i <= down; i++)
                {
                    result[index++] = matrix[i][right];
                }
                // Done traversing down
                direction = 2;
                right--;
            }
            // Traverse left
            else if (direction == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    result[index++] = matrix[down][i];
                }
                // Done traversing left
                direction = 3;
                down--;
            }
            // Traverse up
            else if (direction == 3)
            {
                for (int i = down; i >= up; i--)
                {
                    result[index++] = matrix[i][left];
                }
                // Done traversing up
                direction = 0;
                left++;
            }
        }
        return result;
    }
};
// @lc code=end
