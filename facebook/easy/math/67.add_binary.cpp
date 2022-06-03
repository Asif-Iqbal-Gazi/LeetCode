/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
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
    string addBinary(string a, string b)
    {
        /*
        Approach:
        1. Take a sum and carry variable, set sum to carry initially.
        2. Iterate over all the char and convert them to int and add them to sum.
        3. to_string(sum % 2) will be psushed to result string.
        4. Extract carry by sum / 2
        5. Outside the loop check if there is still a carry, if yes add '1' to result string.
        6. Finally reverse "result" and return it.
        */

        int i = a.size() - 1, j = b.size() - 1, sum = 0, carry = 0;
        string res;

        while (i >= 0 || j >= 0)
        {
            sum = carry;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';
            res += ('0' + sum % 2);
            carry = sum / 2;
            i--;
            j--;
        }

        if (carry)
            res += '1';
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end
