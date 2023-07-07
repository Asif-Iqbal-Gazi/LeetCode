/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        /* Approach:
            1.
        */

        vector<int> ans;
        vector<pair<int, int>> freqVec;
        unordered_map<int, int> freqMap;

        // Build the frequenecy map
        for (int x : nums) // O(n)
            freqMap[x]++;

        for (auto it : freqMap) // O(n)
            freqVec.push_back({it.second, it.first});

        // Sort the data structure
        sort(freqVec.begin(), freqVec.end()); // O(n log n)

        while (k)
        {
            ans.push_back(freqVec.back().second);
            freqVec.pop_back();
            k--;
        }

        return ans;
    }
};
// @lc code=end
