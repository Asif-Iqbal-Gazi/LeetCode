/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
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
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        /*
        Approach1: Using set, Time: O(N), Space: O(N)
        Approach2: Iterate over the array and take every (element-1) as index and mark the element at that index negative(if not already negative). Finally see which all elements are positive, add one to them and those are the missing numbers.
        */
        vector<int> res;
        int n = nums.size();
        // Index Marking
        for (int i = 0; i < n; i++)
        {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        // Find the positive elements index
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                res.emplace_back(i + 1);
        }
        return res;
    }
};
// @lc code=end
