/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
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
    int lengthOfLongestSubstring(string s)
    {
        /*
        Approach:
        1. Sliding Window + Unordered_Set -- O(N). SC: O(N)
        */

        // Approach 1
        unordered_set<char> charSet;

        int l = 0, res = 0, n = s.size();

        for (int r = 0; r < n; r++)
        {
            while (charSet.find(s[r]) != charSet.end())
            {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;

        /* Naive Solution
        unordered_map<char, int> map;

        int i = 0, n = s.size(), max_len = 0, curr_len = 0;

        while (i < n)
        {
            auto it = map.find(s[i]);
            if (it == map.end())
            {
                map[s[i]] = i;
                curr_len++;
            }
            else
            {
                curr_len = 0;
                i = it->second;
                map.clear();
            }
            i++;
            max_len = max(curr_len, max_len);
        }
        return max_len;
        */
    }
};
// @lc code=end
