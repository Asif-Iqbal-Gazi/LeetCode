/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
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
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r])
                l = m + 1;
            else if (nums[m] < nums[r])
                r = m;
            else
                r--;
        }
        return nums[l];
    }
};
// @lc code=end
