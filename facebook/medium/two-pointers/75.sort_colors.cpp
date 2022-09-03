/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        /* Approach:
            1. Three Pointer Approach -- T.C: O(N), S.C: O(1)
                Take three pointers l, m, r.
                l & m will point to 0 and r to n-1 initially.
                If arr[m] is 2 swap it with arr[r] and decrement r
                If arr[m] is 1 increment m
                else if arr[m] is 0 swap it with arr[l] and increment both m & l.
        */

        int n = nums.size();
        int l = 0, m = 0, r = n - 1;
        while (m <= r)
        {
            switch (nums[m])
            {
            // If the element is 2
            case 2:
                swap(nums[r--], nums[m]);
                break;
            // If the element is 1
            case 1:
                m++;
                break;
            // If the element is 0
            case 0:
                swap(nums[m++], nums[l++]);
                break;
            }
        }
    }
};
// @lc code=end
