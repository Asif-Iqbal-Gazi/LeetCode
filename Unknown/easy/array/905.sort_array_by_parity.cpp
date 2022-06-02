/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
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
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        /* Approach: Two Pointers */

        int j = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};
// @lc code=end
