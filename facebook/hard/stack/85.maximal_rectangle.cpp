/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        /* Approach:
        1. Using Stack Based Largest Rectangle in Histogram as Sub Problem
            -- T.C : O(R*C), S.C: O(C)
        */

        // Efficient Approach
        int n = matrix.size(), m = matrix[0].size(), res = 0, maxA = 0;
        vector<int> histogram(m, 0);

        // We are gonna build the histogram of heights and pass to the maxAreaRectangle function
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    histogram[j] = 0;
                else
                    histogram[j] += 1;
            }
            // We have histogram ready let's pass it to our helper function
            maxA = maxAreaRectangle(histogram);
            //  Update the result
            res = max(maxA, res);
        }
        return res;
    }

private:
    int maxAreaRectangle(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size(), ans = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                ans = max(ans, (height * width));
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end
