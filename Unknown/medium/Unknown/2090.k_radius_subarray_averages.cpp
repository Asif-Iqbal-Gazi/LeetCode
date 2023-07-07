/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        // Edge Case:
        if (k == 0)
            return nums;

        int l = 0;
        int r = 0;
        int currLen = 0;
        long long sum = 0;
        int n = nums.size();
        vector<int> avg(n, -1);
        int windowLen = 2 * k + 1;

        while (r < n)
        {
            currLen = r - l + 1;
            sum += 1LL * nums[r];
            if (currLen < windowLen)
                avg[l + (r - l) / 2] = -1;
            else
            {
                if (currLen > windowLen)
                {
                    sum -= 1LL * nums[l];
                    l++;
                }
                avg[l + (r - l) / 2] = sum / windowLen;
            }
            r++;
        }

        return avg;
    }
};
// @lc code=end
