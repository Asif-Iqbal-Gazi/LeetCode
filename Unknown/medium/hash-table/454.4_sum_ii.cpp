/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        /* Approach:
        1. Using 4 loops -- TC: O(N^4), SC: O(1)
        2. Using 3 loops + 1 Map -- TC: O(N^3), SC: O(N)
        3. Using 2 loops + 2 Map -- TC: O(N^2), SC: O(N2)
        */

        // Approach 3
        int count = 0;

        unordered_map<int, int> map;
        // Build Map for 3rd & 4th Array
        for (int c : nums3)
            for (int d : nums4)
                map[c + d]++;

        for (int a : nums1)
        {
            for (int b : nums2)
            {
                auto it = map.find(-(a + b));
                if (it != map.end())
                {
                    // Since we want all possible values
                    count += it->second;
                }
            }
        }
        return count;

        /* Approach 2, Gets TLE as well
        int count = 0;

        unordered_map<int, int> map;
        // Build Map for 4th Array
        for (int d : nums4)
            map[d]++;

        for (int a : nums1)
        {
            for (int b : nums2)
            {
                for (int c : nums3)
                {
                    auto it = map.find(-(a + b + c));
                    if (it != map.end())
                    {
                        // Since we want all possible values
                        count += it->second;
                    }
                }
            }
        }
        return count;
        */

        /* Approach 1, Will surely get TLE
        int count = 0;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                for (int c : nums3)
                {
                    for (int d : nums4)
                        if (a + b + c + d == 0)
                            count++;
                }
            }
        }
        return count;
        */
    }
};
// @lc code=end
