/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        /* Approach:
            1. Using Map -- T.C: O(N), S.C: O(N)
            2. Moore's Voting Algorithm -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        int count = 0;
        int candidate = 0;

        for (int x : nums)
        {
            if (count == 0)
                candidate = x;
            if (candidate == x)
                count++;
            else
                count--;
        }
        return candidate;

        /* Approach 1
        unordered_map<int, int> map;
        int majority = nums.size() / 2;

        for (int x : nums)
        {
            map[x]++;
            if (map[x] > majority)
                return x;
        }
        return -1;
        */
    }
};
// @lc code=end
