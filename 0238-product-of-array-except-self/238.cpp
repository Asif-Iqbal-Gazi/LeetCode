class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
         * Approach:
         * 1. Brute Force                     -- T.C: O(N^2), S.C: O(1)
         *      - For each element, multiply all others.
         * 2. Prefix + Suffix Arrays          -- T.C: O(N),   S.C: O(N)
         *      - Build prefix and suffix arrays, multiply at each index.
         * 3. Prefix + Suffix Space Optimized -- T.C: O(N),   S.C: O(1)
         *      - Use output array for prefix pass, running suffix for second pass.
         */

        // Approach 3 -- Prefix + Suffix Space Optimized
        int         n = nums.size();
        vector<int> ans(n, 1);

        // Pass 1: fill ans with prefix products
        for (int i = 1; i < n; i++) ans[i] = ans[i - 1] * nums[i - 1];

        // Pass 2: multiply running suffix into ans
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;

        /* Approach 2 -- Prefix + Suffix Arrays
        int         n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), ans(n);
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];
        for (int i = 0; i < n; i++)
            ans[i] = prefix[i] * suffix[i];
        return ans;
        */

        /* Approach 1 -- Brute Force
        int         n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = 0; j < n; j++)
                if (i != j)
                    product *= nums[j];
            ans[i] = product;
        }
        return ans;
        */
    }
};
