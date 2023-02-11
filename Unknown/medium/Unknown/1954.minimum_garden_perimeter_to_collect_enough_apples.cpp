/*
 * @lc app=leetcode id=1954 lang=cpp
 *
 * [1954] Minimum Garden Perimeter to Collect Enough Apples
 */

// @lc code=start
class Solution
{
private:
    bool isPossible(long long n, long long neededApples)
    {
        long long totalApples = 0;
        totalApples = n * n * n * 4 + n * n * 6 + n * 2;
        return totalApples >= neededApples;
    }

public:
    long long minimumPerimeter(long long neededApples)
    {
        int l = 1;
        int r = 1e5;

        while (l < r)
        {
            int minSideLen = l + (r - l) / 2;
            if (isPossible(minSideLen, neededApples))
                r = minSideLen;
            else
                l = minSideLen + 1;
        }
        return 8 * l;
    }
};
// @lc code=end
