/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
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
    int characterReplacement(string s, int k)
    {
        /* Approach:
            1. Sliding Window : T.C: O(N), S.C: O(N)
        */

        int res = 0;
        int l = 0;
        int n = s.size();
        vector<int> map(26, 0);

        for (int r = 0; r < n; r++)
        {
            map[s[r] - 'A']++;
            int currWindowLength = r - l + 1;

            // if ((currWindowLength - *max_element(map.begin(), map.end())) <= k)
            if ((currWindowLength - getMaxFrequency(map)) <= k)
                res = max(res, currWindowLength);
            else
            {
                map[s[l] - 'A']--;
                l++;
            }
        }

        return res;
    }

private:
    int getMaxFrequency(vector<int> &map)
    {
        int res = -1;
        for (auto x : map)
        {
            if (res < x)
                res = x;
        }
        return res;
    }
};
// @lc code=end
