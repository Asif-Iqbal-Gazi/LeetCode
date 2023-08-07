/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
class Solution {
   private:
    /* Approach 3 -- Recursion + Memoization
    int N;
    int K;
    int GOAL;
    long dp[101][101];
    const int MOD = 1e9 + 7;
    long solveDP(int index, int uniqueCount) {
        // Base Case
        if (index == GOAL)
            return uniqueCount == N;

        long &ans = dp[index][uniqueCount];
        if (ans != -1)
            return ans;

        ans = 0;
        // Case 1: Play a new song
        if (uniqueCount < N)
            ans = (ans + (N - uniqueCount) * solveDP(index + 1, uniqueCount + 1)) % MOD;
        // Case 2: Play an old song
        if (uniqueCount > K)
            ans = (ans + (uniqueCount - K) * solveDP(index + 1, uniqueCount)) % MOD;
        return ans;
    }
    */

    /* Approach 2 -- Recursion (Different Approach)
    long solveRec(int index, int uniqueCount) {
        // Base Case
        if (index == GOAL)
            return uniqueCount == N;

        int ans = 0;
        // Case 1: Play a new song
        if (uniqueCount < N)
            ans = (ans + (N - uniqueCount) * solveRec(index + 1, uniqueCount + 1)) % MOD;
        // Case 2: Play an old song
        if (uniqueCount > K)
            ans = (ans + (uniqueCount - K) * solveRec(index + 1, uniqueCount)) % MOD;
        return ans;
    }
    */

    /* Approach 1 -- Recursion
    vector<int> lastPlayed;
    unordered_map<int, int> songMap;
    int solveRec(int index) {
        // Base Case
        if (index == GOAL)
            return songMap.size() == N;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int last = lastPlayed[i];
            if (songMap.count(i) && (lastPlayed[i] != -1 && (index - lastPlayed[i] - 1 < K)))
                continue;
            songMap[i]++;
            lastPlayed[i] = index;
            ans = (ans + solveRec(index + 1)) % MOD;
            lastPlayed[i] = last;
            if (--songMap[i] == 0)
                songMap.erase(i);
        }
        return ans;
    }
    */

   public:
    int numMusicPlaylists(int n, int goal, int k) {
        /* Approach:
            1. Recursion
            2. Recursion (Different Approach)
            3. Recursion + Memoization -- T.C: O(n * goal), S.C: O(n * goal)
            4. DP (Bottom Up) -- T.C: O(n * goal), S.C: O(n * goal)
        */

        /*
            DP State:
                dp[i][j] = Number of ways to create a playlist of length i using j unique songs
            DP Transition:
                if we want to add a new song to the playlist, we have (N - j) choices
                    dp[i][j] += (N - j + 1) * dp[i - 1][j - 1]
                if we want to add an old song to the playlist, we have (j - K) choices
                    dp[i][j] += dp[i][j] + (j - K) * dp[i - 1][j]
            Final Answer:
                dp[goal][N]
            Base Case:
                dp[0][0] = 1
        */

        // Approach 4 -- DP (Bottom Up)
        const int MOD = 1e9 + 7;

        int dp[goal + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= min(i, n); j++) {
                // Case 1: Play a new song
                dp[i][j] = (1LL * dp[i - 1][j - 1] * (n - j + 1)) % MOD;
                // Case 2: Play an old song
                if (j > k)
                    dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j] * (j - k)) % MOD;
            }
        }

        return dp[goal][n];

        /* Approach 3 -- Recursion + Memoization
        N = n;
        K = k;
        GOAL = goal;
        memset(dp, -1, sizeof(dp));
        return solveDP(0, 0);
        */

        /* Approach 2 -- Recursion (Different Approach)
        N = n;
        K = k;
        GOAL = goal;
        return solveRec(0, 0);
        */

        /* Approach 1 -- Recursion
        N = n;
        K = k;
        GOAL = goal;
        lastPlayed.assign(N, -1);
        return solveRec(0);
        */
    }
};
// @lc code=end
