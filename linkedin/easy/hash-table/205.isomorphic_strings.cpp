/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        /*
        Approach:
        1. Use a hashmap and set.
        2. Idea is to map(s[i]-->t[i]) and at the same time put t[i] in to the set.
        3. Check if map for s[i] does not exist and t[i] not in set. If so, create the map and store t[i] in set.
        4. Now, if map(s[i]) exists, but t[i] is not in the set. e.g: dod, abg. Here, for the second 'd' we will find that a map for 'd' exist (d-->a), but, 'g' is not in the set. So we return false.
        5. Also, if map[s[i]] is not equal to t[i] then also, we return false.
        */
        int n = s.size();
        string test = "";

        unordered_set<char> set;
        unordered_map<char, char> charMap;
        for (int i = 0; i < n; i++)
        {
            if (charMap.count(s[i]) == 0 && set.count(t[i]) == 0)
            {
                charMap[s[i]] = t[i];
                set.insert(t[i]);
            }
            else if (charMap.count(s[i]) == 0 && set.count(t[i]))
                return false;
            else if (charMap[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
