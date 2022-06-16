/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
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
    int numJewelsInStones(string jewels, string stones)
    {
        /* Approach:
        1. Bruteforce -- O(N*M)
        2. Unordered_set -- O(N+M), SC: O(N)
        */

        /* Bruteforce
        int n = jewels.size(), m = stones.size(), res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (jewels[i] == stones[j])
                    res++;
            }
        }
        return res;
        */

        // Unordered_Map
        int count = 0;
        unordered_set<char> set(jewels.begin(), jewels.end());

        for (char c : stones)
        {
            if (set.find(c) != set.end())
                count++;
        }

        return count;
    }
};
// @lc code=end
