/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
   private:
    int K;
    vector<int> ds;
    void solveRec(int lastPicked, int k, int sum, vector<vector<int>> &ans) {
        // Base Case
        if (k == K) {
            if (sum == 0) ans.push_back(ds);
            return;
        }

        for (int i = lastPicked + 1; i <= 9; i++) {
            if (i <= sum) {
                ds[k] = i;
                solveRec(i, k + 1, sum - i, ans);
            }
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        /* Approach:
            1. Recursion + Backtracking -- T.C: O(k*2^k), S.C: O(k)
        */

        // Approach 1
        // Edge Case
        if (k > n) return {};
        K = k;
        ds.assign(k, 0);
        vector<vector<int>> ans;
        solveRec(0, 0, n, ans);
        return ans;
    }
};
// @lc code=end
