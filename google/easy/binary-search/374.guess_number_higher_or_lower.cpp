/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
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
    int guessNumber(int n)
    {
        /* Approach : Simple Binary Search */
        int l = 1, r = n, guessOut = 0;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            guessOut = guess(m);
            if (guessOut == 0)
                return m;
            else if (guessOut < 0)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end
