/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
   public:
    bool isPowerOfFour(int n) {
        /* Approach:
            1. Divide and Check -- T.C: O(log n), S.C: O(1)
            2. Math -- T.C: O(1), S.C: O(1)
            3. Bit Manupulation -- T.C: O(1), S.C: O(1)
        */

        // Approach 3 -- Bit Maniulation
        return (n > 0) && !(n & (n - 1)) && (n & 0x55555555);

        /* Approach 2 -- Math
        // Let n = 4^x
        // Then x = log_4(n)
        // x = 1/2 * log_2(n)
        // As x is interger, then 1/2 * log_2(n) is an integer as well
        // So, log_2(n) needs to be even
        if (n < 1) return false;
        double x = log2(n);
        if (x != (int)x) return false;
        return ((int)x % 2 == 0);
        */

        /* Approach 1 -- Divide and Check
        while (n) {
            if (n == 1) return true;
            if (n % 4) return false;
            n /= 4;
        }
        return false;
        */
    }
};
// @lc code=end
