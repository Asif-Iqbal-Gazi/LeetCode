/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        /* Approach:
            1. Reverse the number and compare with original -- T.C: O(n), S.C: O(1)
            2. Reverse half of the number and compare with other half -- T.C: O(n), S.C: O(1)
        */

        // Approach 2
        // Edge Case
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int y = 0;
        while (x > y)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return x == y || x == y / 10;

        /* Approach 1
        // Edge Case
        if (x < 0)
            return false;

        int t = x;
        long long y = 0;

        while (t)
        {
            y = y * 10 + t % 10;
            t /= 10;
        }
        return x == y;
        */
    }
};
// @lc code=end
