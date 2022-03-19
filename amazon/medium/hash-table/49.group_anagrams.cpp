/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
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
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        /*
        Approach: Use map
        Observe, all strings will consist of lowercase alphabets. (97 to 122 in decimal)
        1. Create an unordered_map<int, vector<string>>
        2. We will calculate unique key as a1e1t1 (for: eat, ate, tea)
        3. While building the map we first calculate the key, if key is not in the map we insert it as vector string against the key in the map.
        4. If it exist, then we grab the value for the key (which is a vector<string>) and push_back our new string.
        */
        int n = strs.size();

        vector<vector<string> > result;
        unordered_map<string, vector<string> > map;

        for (int i = 0; i < n; i++)
        {
            // This key char array will be our char_map
            string key(26, '0');
            // Build the char_map, will be unique for anagrams.
            for (char c : strs[i])
            {
                key[c - 'a'] += 1;
            }
            // If the key is not present insert in our map.
            if (map.find(key) == map.end())
                map[key] = {strs[i]};
            // If key present the grab the value (vector<string>) push_back the string into it.
            else
            {
                map[key].emplace_back(strs[i]);
            }
        }
        // Finally, iterate through our map and build the result vector.
        for (auto it = map.begin(); it != map.end(); it++)
        {
            result.emplace_back(it->second);
        }
        return result;
    }
};
// @lc code=end
