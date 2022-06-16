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
        1. Unordered_set & unordered_map -- O(N), O(N)
            Let's think of this problem mathematically, in terms of Domain (string s) & Range (string t)
            Idea is there shall be "One" to "One" mapping.
            Thus, when "Many" -> "One" detected return false
            & when "One" --> "Many" detected return false.

        Note: Here Map can be used to detect "One" to "Many" mapping
              & Set can be used to detect "Many" to "One" mapping
        */

        /*
        int n = s.size();
        unordered_set<char> charSet;
        unordered_map<char, char> charMap;

        for (int i = 0; i < n; i++)
        {
            auto it = charMap.find(s[i]);
            if (it != charMap.end())
            {   // "One" to "Many" detection
                if (t[i] != it->second)
                    return false;
            }
            else
            {   // "Many" to "One" detection
                if (charSet.find(t[i]) != charSet.end())
                    return false;
                else
                {
                    charSet.insert(t[i]);
                    charMap[s[i]] = t[i];
                }
            }
        }
        return true;
        */

        int n = s.size();

        unordered_set<char> set;           // Necessary to detect "Many" to "One" mapping
        unordered_map<char, char> charMap; // Necessary to detect "One" to "Many" mapping

        for (int i = 0; i < n; i++)
        {
            if (charMap.count(s[i]) == 0 && set.count(t[i]) == 0)
            { // Both Set & Map are empty so, push to the container
                charMap[s[i]] = t[i];
                set.insert(t[i]);
            }
            else if (charMap.count(s[i]) == 0 && set.count(t[i])) // "Many" to "One" detected
                return false;
            else if (charMap[s[i]] != t[i]) // "One" to "Many" detected
                return false;
        }
        return true;
    }
};
// @lc code=end
