/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
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
    vector<int> plusOne(vector<int> &digits)
    {
        /*
        Approach1:
        Using loop start from right, if the digit is not 9 increment it and break, else set it to 0
        Approach2:
        Take carry and num variable, initially set carry to 1. Using loop iterate over digits array from right. Set num = digits[i] + carry, then set digits[i] = num%10 & carry = num/10. Finally check if carry is 1, if so, insert 1 at the beginning.
        */

        /* Approach 1
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i] += 1;
                break;
            }
            else
            {
                digits[i] = 0;
            }
        }
        if (digits[0] == 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
        */
        // Approach 2
        int n = digits.size(), carry = 1, num = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            num = digits[i] + carry;
            carry = num / 10;
            digits[i] = num % 10;
        }
        if (carry)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end
