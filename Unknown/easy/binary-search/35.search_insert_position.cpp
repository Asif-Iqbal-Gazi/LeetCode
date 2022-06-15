/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
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
    int searchInsert(vector<int> &nums, int target)
    {
        /* Approach: Simple Binary Search */
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end
