/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        /* Approach:
        1. Unordered_Map -- TC: O(NlogN), SC: O(N)
        2. Bucket Sort -- TC: O(N), SC: O(N)
            Create a vector<vector<int>> and use freuency as index,
            and for value store elements with the index frequency.
        */

        // Approach 2
        vector<int> result;
        unordered_map<int, int> map;
        /* Now create our container with the size n+1. (Cause, in worst case,
        when all elements are identical our container will have largest index = n+1)
        */
        vector<vector<int>> bucket(nums.size() + 1);
        // Build frequency map
        for (int x : nums)
            map[x]++;
        // Iterate over map and fill our container
        for (auto x : map)
        {
            bucket[x.second].emplace_back(x.first);
        }
        // Build result
        for (int i = bucket.size() - 1; i >= 0; i--)
        {
            for (int j = bucket[i].size() - 1; j >= 0; j--)
            {
                result.emplace_back(bucket[i][j]);
                if (result.size() == k)
                    return result;
            }
        }

        return result;

        /* Approach 1
        vector<int> result;
        vector<pair<int, int>> freqVec;
        unordered_map<int, int> freqMap;

        // Build Map -- O(N)
        for (int a : nums)
            freqMap[a]++;
        // Build frequency vector -- O(N)
        freqVec.reserve(freqMap.size());
        for (auto it : freqMap)
            freqVec.push_back({it.second, it.first});
        // Sort frequency vector -- O(NlogN)
        sort(freqVec.begin(), freqVec.end());
        // Get K largest frequencies by deleting rest of the element
        freqVec.erase(freqVec.begin(), freqVec.end() - k);
        // Get K frequent element O(N)
        for (auto p : freqVec)
            result.push_back(p.second);
        return result;
        */
    }
};
// @lc code=end
