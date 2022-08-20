/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
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
    vector<int> countBits(int n)
    {
        /* Approach:
            1. Bit Manipulation -- T.C: O(N), S.C: O(1)
                Fastest way to calculate no of 1 bits in a no 'a' is by a AND (a-1)
            2. DP -- T.C: O(N), S.C: O(1)
        */

        /* Approach 1
        vector<int> ans(n + 1, 0);

        while (n)
        {
            int x = n;
            int res = 0;
            while (x)
            {
                x = x & (x - 1);
                res++;
            }
            ans[n--] = res;
        }
        return ans;
        */

        // Approach 2
        int offset = 1;
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (offset * 2 == i)
                offset = i;
            ans[i] = 1 + ans[i - offset];
        }
        return ans;
    }
};
// @lc code=end
