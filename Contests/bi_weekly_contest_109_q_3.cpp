/*
    2787. Ways to Express an Integer as Sum of Powers
    https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
*/

class Solution {
   private:
    const int MOD = 1e9 + 7;
    int x;
    int dp[301][301];
    int getPower(int b) {
        int ans = 1;
        for (int i = 0; i < x; i++) {
            ans *= b;
            if (ans > 300)
                return 301;
        }
        return ans;
    }
    int solveDP(int val, int start) {
        // Base Cases
        if (val == 0)
            return 1;
        if (start > 300)
            return 0;

        int &ans = dp[val][start];
        if (ans != -1)
            return ans;

        ans = 0;
        int powered = getPower(start);
        if (powered <= val)
            ans = (ans + solveDP(val - powered, start + 1)) % MOD;
        ans = (ans + solveDP(val, start + 1)) % MOD;
        return ans;
    }
    /* Approach 2
    int solveDP (int n, int l) {
        // Base Case
        if (n == 0)
            return 1;

        if (dp[n][l] != -1)
            return dp[n][l];

        int ans = 0;
        for (int i = l + 1; i <= n; i++) {
            int powered = pow(i, x);
            if (powered > n) break;
            ans = (ans + solveDP(n - powered, i)) % MOD;
        }
        return dp[n][l] = ans % MOD;

    }
    */
    /* Approach 1
    int solveRec(int n, int x, int l) {
        // Base Case
        if(n == 0) {
            return 1;
        }
        int ans = 0;
        for(int i = l + 1; i <= n; i++) {
            int powered = pow(i, x);
            if(pow(i, x) > n) break;
            ans = (ans + solveRec(n - powered, x, i)) % MOD;
        }
        return ans % MOD;
    }
    */
   public:
    int numberOfWays(int n, int _x) {
        /* Approach:
            1. Recursion -- Exponential
            2. DP -- T.C: O(n^3), S.C: O(n^2)
            3. DP (Optimised) -- T.C: O(n^2), S.C: O(n^2)
                -- Here, we have optimised using pick or not pick approach
        */
        x = _x;
        memset(dp, -1, sizeof(dp));
        return solveDP(n, 1);
    }
};