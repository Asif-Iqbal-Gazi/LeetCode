/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
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
    int arrayPairSum(vector<int> &nums)
    {
        /*
        Approach:
        1. Sort the array
        2. Then starting from zeroth index iterate two number's at a time, and add the first one to the sum.
        3. Return sum at the end.
        */
        int n = nums.size(), sum = 0;
        if (n == 2)
            return min(nums[0], nums[1]);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i += 2)
        {
            sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end
