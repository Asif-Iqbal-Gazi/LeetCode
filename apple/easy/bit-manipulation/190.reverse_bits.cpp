/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
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
    uint32_t reverseBits(uint32_t n)
    {
        /* Approach : Bit Manipulation */
        uint32_t res = 0;

        for (int i = 0; i < 32; i++)
        {
            int bit = (n >> i) & 1;
            res = res | (bit << (31 - i));
        }
        return res;
    }
};
// @lc code=end
