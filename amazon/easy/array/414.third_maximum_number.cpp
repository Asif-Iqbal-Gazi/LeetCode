/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
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
    int thirdMax(vector<int> &nums)
    {
        long long f, s, t = LLONG_MIN;
        int n = nums.size();
        f = s = t;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == t || nums[i] == s || nums[i] == f)
                continue;
            if (nums[i] > f)
            {
                t = s;
                s = f;
                f = nums[i];
            }
            else if (nums[i] > s && nums[i] < f)
            {
                t = s;
                s = nums[i];
            }
            else if (nums[i] > t && nums[i] < s)
            {
                t = nums[i];
            }
        }
        return (t != LLONG_MIN) ? t : f;
    }
};
// @lc code=end
