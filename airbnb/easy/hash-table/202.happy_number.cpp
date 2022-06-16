/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
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
    bool isHappy(int n)
    {
        /* Approach:
        1. Unordered_set : O(logN)
            Extract Digits and then get square sum of digits and store them in set.
            When repeats break loop
        */

        unordered_set<int> s({n});

        while (n != 1)
        {
            int sum = 0, r = 0;
            while (n)
            {
                r = n % 10;
                n /= 10;
                sum += r * r;
            }
            n = sum;
            if (s.find(n) != s.end())
                return false;
            s.insert(n);
        }
        return s.find(1) == s.end() ? false : true;
    }
};
// @lc code=end
