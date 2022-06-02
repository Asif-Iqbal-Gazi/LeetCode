/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
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
    int heightChecker(vector<int> &heights)
    {
        /*
        Approach: Create a new container with sorted height and then check by looping through the heights.
        */
        int n = heights.size(), res = 0;
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n; i++)
        {
            if (sorted[i] != heights[i])
                res++;
        }
        return res;
    }
};
// @lc code=end
