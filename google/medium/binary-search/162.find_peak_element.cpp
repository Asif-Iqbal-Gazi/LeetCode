/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
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
    int findPeakElement(vector<int> &nums)
    {
        /*
        Approach:
        1. Since, nums[-1] = nums[n] = -∞, there is bound to be a peak(Might be even at the extremes).
        2. We will check our middle elements with it's neighbour.
        3. If nums[m]<nums[m+1] we know for sure 'm' is not our peak so we will update l = m+1.
        4. However, if that is not the case, then we will update r = m. (Why not r=m-1 ?? Well, because, it might be the case, that from nums[-1] to nums[m] it is strictly increasing, thus, nums[m-1]<nums[m])
        */

        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
// @lc code=end
