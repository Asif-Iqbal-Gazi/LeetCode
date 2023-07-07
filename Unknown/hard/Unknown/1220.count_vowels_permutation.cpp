/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution
{
public:
    int countVowelPermutation(int n)
    {
        /* Approach:
            "a" -> "e"
            "e" -> "a"
            "e" -> "i"
            "i" -> "a"
            "i" -> "e"
            "i" -> "o"
            "i" -> "u"
            "o" -> "i"
            "o" -> "u"
            "u" -> "a"

            1. DP (Bottom Up) -- T.C: O(n), S.C: O(n)
            2. DP (Space Optimised) -- T.C: o(n), S.C: O(1)
        */

        /*
        DP State:
            dp[i][j]: Count of permutations upto ith length s.t previously selected 'j'
        DP Transistion:
            dp[i][j] = dp[i - 1][map[j][k]]; k = 0 -> map[j].size();
        Base Case:
            dp[0][i] = 0; for all i = 0 -> 5
        Answer:
            sum(dp[n - 1][i]); for all i = 0 -> 5
        */

        // Approach 2
        const int MOD = 1e9 + 7;
        int prev[5];
        int curr[5];

        // Base Case
        for (int i = 0; i < 5; i++)
        {
            prev[i] = 1;
        }

        // a = 0, e = 1, i = 2, o = 3, u = 4;
        vector<vector<int>> map = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                curr[j] = 0;
                for (int k = 0; k < map[j].size(); k++)
                {
                    curr[j] = (curr[j] + prev[map[j][k]]) % MOD;
                }
            }
            swap(prev, curr);
        }

        // Answer
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {
            ans = (ans + prev[i]) % MOD;
        }
        return ans;

        /* Approach 1
        const int MOD = 1e9 + 7;
        int dp[n][5];

        // Base Case
        for(int i = 0; i < 5; i++) {
            dp[0][i] = 1;
        }

        // a = 0, e = 1, i = 2, o = 3, u = 4;
        vector<vector<int>> map = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2,3}};

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                dp[i][j] = 0;
                for(int k = 0; k < map[j].size(); k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][map[j][k]]) % MOD;
                }
            }
        }

        // Answer
        int ans = 0;
        for(int i = 0; i < 5; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        return ans;
        */
    }
};
// @lc code=end
