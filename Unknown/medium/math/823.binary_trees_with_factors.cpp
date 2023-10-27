/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
class Solution {
   public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        /* Approach:
            1. DP -- T.C: O(N^2), S.C: O(N)
        */

        // Approach 1 -- DP
        int n = arr.size();
        int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<long, long> subtreeCount;

        for (long root : arr) {
            subtreeCount[root] = 1;

            // Check for subtree count
            for (long factor : arr) {
                if (factor > root) break;
                if (root % factor == 0 && subtreeCount.count(root / factor))
                    subtreeCount[root] += subtreeCount[factor] * subtreeCount[root / factor];
            }
        }

        int totalTrees = 0;
        for (const auto& entry : subtreeCount) {
            totalTrees = (totalTrees % MOD + entry.second % MOD) % MOD;
        }
        return totalTrees;
    }
};
// @lc code=end
