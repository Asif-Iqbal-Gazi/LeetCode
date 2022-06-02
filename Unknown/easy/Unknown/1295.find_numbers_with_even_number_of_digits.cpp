/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
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
    int countDigit(int n)
    {
        int c = 0;
        while (n)
        {
            n = n / 10;
            c++;
        }
        return c;
    }
    int findNumbers(vector<int> &nums)
    {
        /* Approach:
        1. Converting to String
        2. Counting digits using while loop
        */

        /* Approach 1
         int n = nums.size(), res = 0;
         string num;
         for (int i = 0; i < n; i++)
         {
             num.clear();
             num = to_string(nums[i]);
             if (num.length() % 2 == 0)
             {
                 res++;
             }
         }
         return res;
         */

        // Approach 2
        int n = nums.size(), len = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            len = countDigit(nums[i]);
            if (len % 2 == 0)
                res++;
        }
        return res;
    }
};
// @lc code=end
