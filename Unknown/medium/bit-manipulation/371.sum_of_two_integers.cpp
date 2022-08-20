/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
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
    int getSum(int a, int b)
    {
        /* Approach:
            1. Bit Manipulation
                Basically, A XOR B gives us A + B without carry.
                And A AND B left shifted to 1 gives us integer with carry.
                Thus we need add the above two numbers agains untill carry becomes zero.
                NOTE: In C/C++ Left shifting of signed number is undefined.
        */
        while (b != 0)
        {
            int temp = a & b;        // Temp variable, as 'a' gets destroyed
            a = a ^ b;               // Sum part without carry
            b = (unsigned)temp << 1; // Signed becuase left shifting a negative value in C/C++ is undefined
        }
        return a;
    }
};
// @lc code=end
