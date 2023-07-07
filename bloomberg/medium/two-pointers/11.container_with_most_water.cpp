/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(1)
            2. Two Pointers -- T.C: O(n), S.C: O(1)
        */

        // Approach 2
        int ans = 0;
        int area = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;

        /* Approach 1
        int ans = 0;
        int area = 0;
        int n = height.size();

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                area = (j - i) * min(height[i], height[j]);
                ans = max(ans, area);
            }
        }

        return ans;
        */
    }
};
// @lc code=end
