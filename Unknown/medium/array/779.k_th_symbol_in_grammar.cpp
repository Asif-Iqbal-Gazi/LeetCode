/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution {
   public:
    int kthGrammar(int n, int k) {
        /* Approach:
            1. Recursion -- T.C: O(n), S.C: O(n)
            2. Math -- T.C: O(log k), S.C: O(1)
        */

        /* Observation:
            Observe, for n = 4 our rows are:
                0
                0 1
                0 1 1 0
                0 1 1 0 1 0 0 1
            => Each row doubles
            => Each rows 1st half is same as previous row.
            => Each rows 2nd half is inverted of the previous row
        */

        // Approach 2 -- Math
        int count = __builtin_popcount(k - 1);
        return count % 2 == 0 ? 0 : 1;

        /* Approach 1 -- Recursion
        // Base Case
        if (n == 1 && k == 1) return 0;

        // int mid = pow(2, n - 1) / 2;
        int mid = pow(2, n - 2);

        if (k <= mid) return kthGrammar(n - 1, k);
        else return 1 - kthGrammar(n - 1, k - mid);
        */
    }
};
// @lc code=end
