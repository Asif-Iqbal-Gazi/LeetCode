/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
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
    int hammingWeight(uint32_t n)
    {
        /* Approach: Bit Manipulation
            AND n with 1 and then with 2 ans so on.
        */
        int res = 0;
        int i = 0;
        while (i < 32)
        {
            if (n & (1 << i))
                res++;
            i++;
        }
        return res;
    }
};
// @lc code=end
