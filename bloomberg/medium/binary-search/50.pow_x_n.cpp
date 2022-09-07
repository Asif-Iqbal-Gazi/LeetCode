/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N), S.C: O(1)
            2. Binary Search: T.C: O(log N), S.C: O(1)
        */

        /* Approach 1
        double res = 1;

        for (int i = 0; i < n; i++)
            res *= x;

        return n > 0 ? res : 1 / res;
        */

        // Approach 2
        double res = 1;

        while (n)
        {
            if (n % 2)
                res = (n > 0) ? res * x : res / x;
            // Multiply x with x;
            x = x * x;
            // Half n
            n = n / 2;
        }
        return res;
    }
};
// @lc code=end
