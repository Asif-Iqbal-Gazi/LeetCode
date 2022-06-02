/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
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
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        /*
        Approach: Two Variables
        */
        int n = nums.size();
        int result = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
            {
                count++;
                result = max(count, result);
            }
            else
            {
                count = 0;
            }
        }
        return result;
    }
};
// @lc code=end
