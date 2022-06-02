/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
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
    void moveZeroes(vector<int> &nums)
    {
        /*
        Approach: Take a index pointer ans set it to zero, now iterate over the array and whenever an element is not zero place it at arr[index] and then increment index. Finally, fill the rest of the array with zeros.
        */
        int i = 0, index = 0, n = nums.size();
        for (i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                nums[index++] = nums[i];
        }
        for (i = index; i < n; i++)
        {
            nums[i] = 0;
        }
    }
};
// @lc code=end
