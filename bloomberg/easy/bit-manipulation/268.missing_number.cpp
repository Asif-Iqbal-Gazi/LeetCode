/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
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
    int missingNumber(vector<int> &nums)
    {
        /* Approach:
            1. Algebra -- T.C: O(N), S.C: O(1)
            2. XOR Technique -- T.C: O(N), S.C: O(1)
        */

        /* Approach 1
        int n = nums.size();
        int missingNumber = n * (n + 1) / 2;

        for (auto x : nums)
            missingNumber -= x;

        return missingNumber;
        */

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i <= n; i++)
        {
            if (i != n)
                ans ^= nums[i];
            ans ^= i;
        }
        return ans;
    }
};
// @lc code=end
