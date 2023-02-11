/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
private:
    bool isPossible(vector<int> &piles, const int h, int maxK)
    {
        int totalTime = 0;
        for (auto x : piles)
        {
            if (x <= maxK)
                totalTime++;
            else
                totalTime += ((x / maxK) + ((x % maxK == 0) ? 0 : 1));

            if (totalTime > h)
                return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        /* Approach:
            1. Binary Search -- T.C: O(nlogn), S.C: O(1)
        */

        int l = 1;
        int r = 1e9 + 1;

        while (l < r)
        {
            int minK = ((r - l) >> 1) + l;
            if (isPossible(piles, h, minK))
                r = minK;
            else
                l = minK + 1;
        }
        return l;
    }
};
// @lc code=end
