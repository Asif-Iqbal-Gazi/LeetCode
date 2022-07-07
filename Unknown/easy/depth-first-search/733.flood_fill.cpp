/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
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
    void doDFS(vector<vector<int>> &image, int i, int j, int row, int col, int newColor, int prevColor)
    {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return;
        if (image[i][j] == prevColor)
        {
            image[i][j] = newColor;
            doDFS(image, i + 1, j, row, col, newColor, prevColor);
            doDFS(image, i - 1, j, row, col, newColor, prevColor);
            doDFS(image, i, j + 1, row, col, newColor, prevColor);
            doDFS(image, i, j - 1, row, col, newColor, prevColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        /* Approach:
            1. DFS -- T.C: O(N)
        */

        // Standard DFS -- Recursion
        // If already painted return image
        if (image[sr][sc] == color)
            return image;

        int row = image.size();
        int col = image[0].size();

        doDFS(image, sr, sc, row, col, color, image[sr][sc]);
        return image;

        /* Standard DFS -- Iterative
        // If already painted return image
        if (image[sr][sc] == color)
            return image;

        int row = image.size();
        int col = image[0].size();
        int prevColor = image[sr][sc];

        stack<pair<int, int>> st;
        unordered_set<string> seen;
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        st.push({sr, sc});
        seen.insert(to_string(sr) + "," + to_string(sc));

        while (!st.empty())
        {
            pair<int, int> p = st.top();
            st.pop();
            // Paint the pixel
            image[p.first][p.second] = color;

            for (int i = 0; i < 4; i++)
            {
                // Check if neighboring pixels has prev color and not added to the seen set
                int nR = p.first + direction[i][0];
                int nC = p.second + direction[i][1];

                if (nR >= 0 && nR < row &&
                    nC >= 0 && nC < col &&
                    image[nR][nC] == prevColor &&
                    seen.find(to_string(nR) + "," + to_string(nC)) == seen.end())
                {
                    // Add to seen set to avoid duplication
                    seen.insert(to_string(nR) + "," + to_string(nC));
                    // Push the pixel coordinate into the stack
                    st.push({nR, nC});
                }
            }
        }
        return image;
        */
    }
};
// @lc code=end
