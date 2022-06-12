/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
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
    int search(vector<int> &nums, int target)
    {
        /*
        Approach:
        1. Observe, during our first mid, we would have at least one strictly increasing side.
        2. After calculating mid, check if the element is at mid, if so return.
        3. Else check if the left side is strictly increasing by comparing mid and left. If yes, now check if our target falls in this range, if yes, make r=mid-1, if no, then make l=mid+1
        4. However, if left side was not strictly increasing then right side has to be. Thus, now check if our target falls in this side(right), if so make l=mid+1, else r=mid-1
        */
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            // Check if leftside is strictly increasing
            else if (nums[l] <= nums[m])
            {
                // We found left side is increasing, now check if our number falls in this range
                if (target >= nums[l] && target <= nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            // Else, right side must be strictly increasing
            else
            {
                // Check if our number falls in this range
                if (target >= nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        // Number not present
        return -1;
    }
};
// @lc code=end
