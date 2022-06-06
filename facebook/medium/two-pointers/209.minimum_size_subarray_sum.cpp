/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        /*
        Approach: Sliding Window
        1. Use two pointer and start at index zero.
        2. First while the sum is not greater than or equal to target keep on moving right pointer.
        3. Once the sum is greater than or equal target, compress the window by moving the left pointer to right untill we are less than target.
        4. When that happens update our window length as min(min_size, (r-l+2)).
        5. Since we are now less than our target move the right pointer again.
        6. Continue untill right pointer is out of bound.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int l = 0, r = 0, sum = 0, n = nums.size(), min_size = INT_MAX;

        while (r < n)
        {
            sum += nums[r];

            while (sum >= target)
            {
                min_size = min(min_size, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return (min_size == INT_MAX) ? 0 : min_size;
    }
};
// @lc code=end
