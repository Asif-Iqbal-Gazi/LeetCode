/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        /*
        Approach 1: Brute force
        Approach 2: Hash Map
        1. Create a map of 101 elements.
        2. Iterate through the nums and set the frequencies in the map array.
        3. Create a new map for storing the cumulative frequency.
        3. Iterate through the map array and new map to build the cumulative frequency.
        4. Iterate through the nums array and take each element as key find the updated frequency from map array and push it into result vector.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        /* Approach 1
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (nums[i] > nums[j])
                    count++;
            }
            res.emplace_back(count);
        }
        return res;
        */

        /* Approach 2*/
        int n = nums.size();
        vector<int> map(101, 0);
        vector<int> c_map(101, 0);
        vector<int> res(n, 0);

        // Get the normal frequency
        for (int i : nums)
            map[i]++;
        // Build the cumulative frequencies
        for (int i = 1; i < 101; i++)
            c_map[i] = c_map[i - 1] + map[i - 1];
        // Build the result vector from cumulative frequency
        for (int i = 0; i < n; i++)
        {
            res[i] = c_map[nums[i]];
        }
        return res;
    }
};
// @lc code=end
