/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
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
    int divide(int dividend, int divisor)
    {
        /* Approach : Binary Search
        1. The idea is shifting divisor and checking if (dividend - divisor) is still positive
        */

        int result = 0;
        // Edge Cases
        if (divisor == INT_MIN)
            if (dividend == divisor)
                return 1;
            else
                return 0;

        if (dividend == INT_MIN)
            if (divisor == 1)
                return INT_MIN;
            else if (divisor == -1)
                return INT_MAX;
            else
                dividend += abs(divisor), result++; // INT_MIN + abs(divisor) / abs(divisor) = 1 + INT_MIN / abs(divisor)

        // Determine the sign of the result
        int sign = ((dividend >= 0) == (divisor >= 0)) ? 1 : 0;
        dividend = abs(dividend);
        divisor = abs(divisor);

        while (dividend >= divisor)
        {
            int t = 1; // multiplier by default 1 since (dividend >= divisor)
            int curr_dvs = divisor;
            int curr_dvd = dividend >> 1;

            while (curr_dvd >= divisor)
            {
                curr_dvs = curr_dvs << 1;
                t = t << 1;
                curr_dvd = curr_dvd >> 1;
            }

            dividend -= curr_dvs;
            result += t;
        }
        return sign ? result : -result;
    }
};
// @lc code=end
