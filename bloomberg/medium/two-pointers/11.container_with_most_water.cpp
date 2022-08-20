/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
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
    int maxArea(vector<int> &height)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N^2), S.C: O(1) -- Gets TLE
            2. Two Pointer Approach -- T.C: O(N), S.C: O(1)
        */

        /* Bruteforce
        int res = 0;
        int n = height.size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int area = (j-1)*min(height[i],height[j]);
                res = max(res, area);
            }
        }
        return res;
        */

        // Two Pointer Optimal Approach
        int res = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r)
        {
            int area = (r - l) * min(height[l], height[r]);
            res = max(res, area);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};
// @lc code=end
