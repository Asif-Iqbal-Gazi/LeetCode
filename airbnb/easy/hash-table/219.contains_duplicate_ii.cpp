/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
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
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        /*
        Approach : Using Map
        1. While iterating over the array look if the number is alredy present in map.
        2. If present check, it's current position minus - last position (value in map is position) is less or equal 1. If so, return true, else update it's postiion.
        3. If not present insert in map with it's position as value.
        */

        int n = nums.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                if (i - map[nums[i]] <= k)
                    return true;
                else
                    map[nums[i]] = i;
            }
            else
                map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
