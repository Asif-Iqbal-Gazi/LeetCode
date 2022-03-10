/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution
{
public:
    int digitSquareSum(int n)
    {
        int r = 0, sum = 0;
        while (n > 0)
        {
            r = n % 10;
            sum += r * r;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        /*
        Approach : HashMap
        1. Try some number like 4, 5 and observe that this number loops endlessly.
        2. We will use the above fact to break out of our loop.
        3. The idea is to for a number compute the sum of the swaure of it's digits.
        4. Check if the sum is already in the set. If yes, immediately return false.
        5. Else, insert it in the set and set n = sum
        */

        unordered_set<int> set({n});
        while (n != 1)
        {
            int sum = digitSquareSum(n);
            if (set.find(sum) != set.end())
                return false;
            else
            {
                set.insert(sum);
                n = sum;
            }
        }
        return true;
    }
};
// @lc code=end
