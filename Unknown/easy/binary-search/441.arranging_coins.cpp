/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
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
    int arrangeCoins(int n)
    {
        /* Approach :
        1. Bruteforce
        2. Binary Search
        3. Math Equation
        */

        /* Bruteforce
        int row = 1;
        while (n >= row)
        {
            n -= row;
            row++;
        }
        return row - 1;
        */

        /* Approach 2 Binary Search
        int low = 1, high = n, ans = 0;
        long long mid, totalPossibleCoins;
        while (low <= high)
        {
            mid = low + ((high - low) >> 1);
            totalPossibleCoins = (mid * (mid + 1)) >> 1;
            if (totalPossibleCoins > n)
                high = mid - 1;
            else
            {
                low = mid + 1;
                ans = mid;
            }
        }
        return ans;
        */

        // Math Equation
        return sqrt(2l * n + 0.25) - 0.5;
    }
};
// @lc code=end
