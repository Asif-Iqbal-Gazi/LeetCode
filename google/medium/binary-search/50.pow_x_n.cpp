/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
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
    double myPow(double x, int n)
    {
        double result = 1;
        while (n)
        {
            if (n % 2)
                result = (n > 0) ? result * x : result / x;
            x = x * x;
            n /= 2;
        }
        return result;
    }
};
// @lc code=end
