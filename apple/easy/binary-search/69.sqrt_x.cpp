/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
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
    int mySqrt(int x)
    {
        /*
        Approach:
        1. Simple binary search.
        2. To avoid overflow make m = l + (h-l)/2 and during checking instead of m*m > x, do m > x/m instead.
        3. Finally, since we want to truncate result, before returning check if result* result > x, if so return result - 1.
        */
        if (x == 0 || x == 1)
            return x;
        int l = 1, r = x;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (m == x / m)
                return m;
            else if (m > x / m)
                r = m - 1;
            else
                l = m + 1;
        }
        return (l > x / l) ? l - 1 : l;
    }
};
// @lc code=end
