/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
   private:
    int N;
    int dp[2001][2001];
    int isPossible(int prevJump, int index, vector<int>& stones) {
        if (index == N - 1)
            return 1;

        // Check if cached
        if (dp[index][prevJump] != -1)
            return dp[index][prevJump];

        bool ans = false;
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump <= 0) continue;
            int nextIndex = lower_bound(stones.begin() + index, stones.end(), stones[index] + nextJump) - stones.begin();
            if (nextIndex == N || (stones[nextIndex] - stones[index] != nextJump)) continue;
            ans |= isPossible(nextJump, nextIndex, stones);
        }

        return dp[index][prevJump] = ans;
    }
    /* Approach 1
    unordered_map<int, int> stonesMap;
    int isPossible(int k, int index, vector<int>& stones) {
        if (index == N - 1)
            return 1;

        // Check if cached
        if (dp[index][k] != -1)
            return dp[index][k];

        bool ans = false;
        // Case 1 -- 'K - 1' unit jump
        if (k > 1 && stonesMap.count(stones[index] + k - 1)) ans |= isPossible(k - 1, stonesMap[stones[index] + k - 1], stones);
        // Case 2 -- 'K' unit jump
        if (k && stonesMap.count(stones[index] + k)) ans |= isPossible(k, stonesMap[stones[index] + k], stones);
        // Case 3 -- 'K + 1' unit jump
        if (stonesMap.count(stones[index] + k + 1)) ans |= isPossible(k + 1, stonesMap[stones[index] + k + 1], stones);

        return dp[index][k] = ans;
    }
    */
   public:
    bool canCross(vector<int>& stones) {
        /* Approach:
            1. DP (Recusrison + Memoization) -- T.C: O(N^2), S.C: O(N^2)
            2. Same as above but with bianry Search -- T.C: O(N^2 * log N), S.C: O(N^2)
        */

        // Approach 2 -- DP (Recursion + Memoization + Binary Search)
        N = stones.size();
        memset(dp, -1, sizeof(dp));

        return isPossible(0, stones[0], stones);

        /* Approach 1 -- DP (Recusrison + Memoization)
        N = stones.size();
        stonesMap.clear();
        memset(dp, -1, sizeof(dp));

        // Build the stonesMap
        for (int i = 0; i < N; i++)
            stonesMap[stones[i]] = i;

        return isPossible(0, stones[0], stones);
        */
    }
};
// @lc code=end
