/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
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
    int dominantIndex(vector<int> &nums)
    {
        /*
        Approach:
        1. Using one loop find both the largest and second largest number.
        2. Check if the largest is at least twice as much as second largest.
        */

        int max = 0, secondMax = 0, resIndex = 0, n = nums.size();
        // Special Case
        if (n == 1)
            return 0;
        // Find the Max and SecondMax
        for (int i = 0; i < n; i++)
        {
            if (max < nums[i])
            {
                resIndex = i;
                secondMax = max;
                max = nums[i];
            }
            else if (secondMax < nums[i] && nums[i] < max)
            {
                secondMax = nums[i];
            }
        }
        return max >= 2 * secondMax ? resIndex : -1;
    }
};
// @lc code=end
