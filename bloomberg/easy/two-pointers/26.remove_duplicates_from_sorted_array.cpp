/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
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
    int removeDuplicates(vector<int> &nums)
    {
        /* Approach : Two Pointers */
        int n = nums.size();
        int index = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
                nums[index++] = nums[i];
        }
        return index;
    }
};
// @lc code=end
