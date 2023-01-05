/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
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
    int firstUniqChar(string s)
    {
        /*
        Approach:
        1. Using Map
            Create map for each character with it's frequency
            Next check for frequency and if it is 1 then return the index
        */

        int n = s.size();
        int seen[26] = {0};

        // Building Charmap
        for (char c : s)
            seen[c - 'a']++;

        // Iterate through the string again.
        for (int i = 0; i < n; i++)
            if (seen[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};
// @lc code=end
