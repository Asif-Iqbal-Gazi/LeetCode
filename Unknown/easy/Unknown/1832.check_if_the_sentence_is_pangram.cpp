/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        /* Approach:
            1. Using Map -- T.C: O(n), S.C: O(1)
        */

        int map[26];
        int count = 0;

        memset(map, 0, sizeof(map));

        for (char c : sentence)
        {
            if (map[c - 'a'] == 0)
                count++;
            map[c - 'a']++;
            if (count == 26)
                return true;
        }

        return false;
    }
};
// @lc code=end
