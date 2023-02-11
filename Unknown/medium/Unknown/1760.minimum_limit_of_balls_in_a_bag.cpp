/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
class Solution
{
private:
    bool isPossible(vector<int> &nums, const int k, int minPenalty)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= minPenalty)
                continue;
            count += nums[i] / minPenalty;
            if (nums[i] % minPenalty == 0)
                count--;
            if (count > k)
                return false;
        }
        return count <= k;
    }

public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        /* Approach:
            1. Binary Search -- T.C: O(nlogn), S.C: O(n)
        */

        int l = 1;
        int r = 1e9 + 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (isPossible(nums, maxOperations, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end
