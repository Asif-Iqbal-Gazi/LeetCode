/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
    int findMin(vector<int> &nums)
    {
        /* Approach :
            1. Bruteforce -- T.C: O(N), S.C: O(1)
            2. Binary Search -- T.C: O(log N), S.C: O(1)
                Calculate mid and decide which side is strictly increasing, using nums[m] > nums[h]
                If it is true, i.e : Left side is strictly increasing then right side will contain our minimum, so update m = l + 1
                However, if not true, then update h = m. (Why not m-1 ? Because, the element at mid might be the smallest element as well.)
        */

        /* Approach 1
        int min = 5001;
        for(auto x : nums){
            if(x < min)
                min = x;
        }
        return min;
        */

        // Binary Search
        int l = 0;
        int h = nums.size() - 1;

        while (l < h)
        {
            // Case: Array is not rotated at all
            if (nums[l] < nums[h])
                return nums[l];
            int m = l + (h - l) / 2;
            if (nums[m] > nums[h])
                l = m + 1; // Left side is strictly increasing, so minimum will be on the rightside
            else
                h = m;
        }
        return nums[l];
    }
};
// @lc code=end
