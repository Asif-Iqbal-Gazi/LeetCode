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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        /*
        Approach:
        1. Unordered_Map -- O(NK), SC(NK)
            Idea: is to create unique map for anagrams.
            Observe, strs[i] contains only lowercase english alphabets (ASCII 97 - 122)
            Thus, we can create a 26 digit long string "0000000....000" initally,
            then based on each strs[i] we can create unique key string (eg: "1110000000..00", for "abc", "bca" etc.)

            With above technique and imploring a Unorder_map<sting, vector<string> we can solve this.
        2. Unordered_Map + Sorted strs[i] as key -- O(NKlogK) , SC: O(NK)
        3. Unique prime for each lowercase alphabet to generate product for string key
            Downside: Overflow (??)
        */

        /* Approach 1
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramMap;

        for (int i = 0; i < n; i++)
        {
            // Initial key
            string key(26, '0');
            // Build charmap for strs[i]
            for (char c : strs[i])
                key[c - 'a']++;

            // New let's build anagram map
            auto it = anagramMap.find(key);
            if (it != anagramMap.end())
            { // String with this key is present, insert the new entry.
                (it->second).emplace_back(strs[i]);
            }
            else
                // A new key
                anagramMap[key] = {strs[i]};
        }

        // Finally, Iterate through our anagramMap for output
        for (auto it = anagramMap.begin(); it != anagramMap.end(); it++)
            result.emplace_back(it->second);
        return result;
        */

        // Approach 2: Sorted strs[i] as key
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramMap;
        // Building anagram map
        for (auto str : strs)
        {
            auto key = str;
            // Sorted strs[i] as key
            sort(key.begin(), key.end());
            anagramMap[key].emplace_back(str);
        }
        // Might save some time during emaplace_back
        result.reserve(anagramMap.size());
        for (auto it : anagramMap)
            result.emplace_back(it.second);
        return result;
    }
};
// @lc code=end
