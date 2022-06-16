/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
        Approach:
        1. Unordered_map -- O(N), SC: O(N)
        */

        int n = nums.size();

        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            if (map.find(target - nums[i]) != map.end())
                return {map.find(target - nums[i])->second, i};
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};
// @lc code=end
