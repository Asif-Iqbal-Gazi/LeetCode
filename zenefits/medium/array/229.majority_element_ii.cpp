/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        /* Approach:
            1. Using Map -- T.C: O(N), S.C: O(N)
            2. Using Moore's Voting Algo -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        vector<int> res;
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int candidate1 = -1, candidate2 = -1;

        for (int x : nums)
        {

            if (x == candidate1)
                count1++;
            else if (x == candidate2)
                count2++;
            else if (count1 == 0)
            {
                candidate1 = x;
                count1++;
            }
            else if (count2 == 0)
            {
                candidate2 = x;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int x : nums)
        {
            if (x == candidate1)
                count1++;
            else if (x == candidate2)
                count2++;
        }
        if (count1 > n / 3)
            res.push_back(candidate1);
        if (count2 > n / 3)
            res.push_back(candidate2);

        return res;

        /* Approach 1
        vector<int> result;
        int n = nums.size();
        int majorityFreq = n / 3;
        unordered_map<int, int> map;

        // Building the map
        for (int x : nums)
        {
            map[x]++;
            if (map[x] > majorityFreq)
            {
                result.push_back(x);
                map[x] = INT_MIN;
            }
        }
        return result;
        */
    }
};
// @lc code=end
