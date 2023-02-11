/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution
{
private:
    bool isPossible(vector<int> &bloomDay, const int maxDay, const int m, const int k)
    {
        int count = 0;
        int consDays = 0;
        for (auto x : bloomDay)
        {
            if (x > maxDay)
                consDays = 0; // Reset the consecutive day
            else
            {
                consDays++; // Increment the consecutive days
                if (consDays == k)
                {
                    count++;      // Increment the count
                    consDays = 0; // Rest the consecutive days
                }
            }
            if (count >= m)
                return true;
        }
        return false;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        /* Approach:
            1. Binary Search -- T.C: O(nlogn), S.C: O(1)
        */

        // Edge Case
        if ((bloomDay.size() / m) < k)
            return -1;

        int l = 0;
        int r = 0;
        // Set the lower and upperbound
        for (auto x : bloomDay)
        {
            l = min(l, x);
            r = max(r, x);
        }

        while (l < r)
        {
            int minDay = l + (r - l) / 2;
            if (isPossible(bloomDay, minDay, m, k))
                r = minDay;
            else
                l = minDay + 1;
        }
        return l;
    }
};
// @lc code=end
