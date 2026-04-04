class Solution {
  public:
    vector<int> countBits(int n) {
        /*
         * Approach:
         * 1. Bit Manipulation (Brian Kernighan) -- T.C: O(N log N), S.C: O(1)
         *      - For each number i, count set bits using i & (i - 1).
         * 2. Dynamic Programming              -- T.C: O(N),       S.C: O(1)
         *      - ans[i] = ans[i >> 1] + (i & 1)
         *      - i >> 1 drops the last bit, its count is already computed.
         *      - i & 1 adds 1 if i is odd, 0 if even.
         */

        // Approach 2 -- DP
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) ans[i] = ans[i >> 1] + (i & 1);
        return ans;

        /* Approach 1 -- Brian Kernighan
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int count = 0;
            int x     = i;
            while (x) {
                x &= (x - 1);
                count++;
            }
            ans[i] = count;
        }
        return ans;
        */
    }
};
