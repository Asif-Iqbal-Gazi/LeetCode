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
        Approach :
        1. Brutefore -- O(N^2)
        2. Unordered_Map - O(N), SC: O(N)
            While iterating over the array look if the number is alredy present in map.
            If present check, it's current position minus - last position (value in map is position) is less or equal 1. If so, return true, else update it's postiion.
            If not present insert in map with it's position as value.
        */

        /* Bruteforce (Gets TLE, as N^2 runtime)
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j] && abs(i - j) <= k)
                    return true;
            }
        }
        return false;
        */

        // Unordered_Map
        int n = nums.size();

        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            auto it = map.find(nums[i]);
            if (it != map.end())
            { // Found a equal element
                if (abs(i - it->second) <= k)
                    return true;
                else
                    // Updating value for this element incase we find same element again
                    map[nums[i]] = i;
            }
            else
                // Element not in map yet, map it
                map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
