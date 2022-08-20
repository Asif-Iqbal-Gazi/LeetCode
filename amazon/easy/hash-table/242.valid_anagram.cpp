/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
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
    bool isAnagram(string s, string t)
    {
        /* Approach:
            1. Using Map : T.C: O(max(N,M)), S.C: O(min(N,M))
        */

        int n = s.size();
        int m = t.size();
        // Edge Case
        if (n != m)
            return false;
        vector<int> map(26, 0);
        // Building Map for 't'
        for (auto c : t)
            map[c - 'a']++;
        // Iterate through 's' and decrement frequency this time
        for (auto c : s)
        {
            if (map[c - 'a'] > 0)
                map[c - 'a']--;
            else
                return false;
        }
        // Iterate through the map now and calculate sum
        int sum = 0;
        for (int x : map)
            sum += x;
        return sum == 0 ? true : false;
    }
};
// @lc code=end
