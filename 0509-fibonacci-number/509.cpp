class Solution {
private:
  int findFib(int n, vector<int>& dp) {
    if (n <= 1)
      return dp[n] = n;
    if (dp[n] != -1)
      return dp[n];
    return dp[n] = findFib(n - 1, dp) + findFib(n - 2, dp);
  }

public:
  int fib(int n) {
    /* Approach:
     *  1. [Recursion] -- T.C: O(2^N), S.C: O(N)
     *  2. [Recursion + Memoizaiton] -- T.C: O(N), S.C: O(N)
     *  3. [DP (Bottom Up)] -- T.C: O(N), S.C: O(N)
     *  4. [DP (Bottom UP + Space Optimization)] -- T.C: O(N), S.C: O(1)
     */

    // Approach 4: DP (Bottom Up + Space Optimization)
    if (n <= 1)
      return n;

    int prev      = 1;
    int prev2prev = 0;

    for (int i = 2; i <= n; i++) {
      int curr  = prev + prev2prev;
      prev2prev = prev;
      prev      = curr;
    }
    return prev;

    /* Approach 3: DP (Bottom Up)
    if (n <= 1)
      return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
    */

    /* Approach 2: Recursion + Memoizaiton
    vector<int> dp(n + 1, -1);
    return findFib(n, dp);
    */

    /* Approach 1: Recursion
    if (n <= 1)
      return n;
    return fib(n - 1) + fib(n - 2);
    */
  }
};
