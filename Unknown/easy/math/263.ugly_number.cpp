/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int n)
    {
        // All negative numbers are not ugly by problem definition
        if (n < 1)
            return false;
        // If has factor '2' reduce
        while (n % 2 == 0)
            n /= 2;
        // If has factor '3' reduce
        while (n % 3 == 0)
            n /= 3;
        // If has factor '5' reduce
        while (n % 5 == 0)
            n /= 5;
        // By this time if it is Ugly number then it would have been reduced to 1
        return (n == 1) ? true : false;
    }
};
// @lc code=end
