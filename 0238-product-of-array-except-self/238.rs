impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
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
        let     n          = nums.len();
        let mut ans        = vec![1i32; n];

        // Pass 1: fill ans with prefix products
        for i in 1..n {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Pass 2: multiply running suffix into ans
        let mut suffix = 1i32;
        for i in (0..n).rev() {
            ans[i] *= suffix;
            suffix  *= nums[i];
        }
        ans

        /* Approach 2 -- Prefix + Suffix Arrays
        let     n          = nums.len();
        let mut prefix     = vec![1i32; n];
        let mut suffix     = vec![1i32; n];
        let mut ans        = vec![0i32; n];
        for i in 1..n {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for i in (0..n - 1).rev() {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        for i in 0..n {
            ans[i] = prefix[i] * suffix[i];
        }
        ans
        */

        /* Approach 1 -- Brute Force
        let     n   = nums.len();
        let mut ans = vec![1i32; n];
        for i in 0..n {
            let mut product = 1i32;
            for j in 0..n {
                if i != j {
                    product *= nums[j];
                }
            }
            ans[i] = product;
        }
        ans
        */
    }
}
