/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution
{
private:
    bool isPossible(vector<int> &nums, int maxDivisor, int k)
    {
        int sum = 0;
        for (auto x : nums)
        {
            sum += ceil((1.0 * x) / maxDivisor);
            if (sum > k)
                return false;
        }
        return true;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (isPossible(nums, m, threshold))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end
