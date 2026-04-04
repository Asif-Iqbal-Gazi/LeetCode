impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
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
        let mut ans = vec![0i32; (n + 1) as usize];
        for i in 1..=(n as usize) {
            ans[i] = ans[i >> 1] + (i & 1) as i32;
        }
        ans

        /* Approach 1 -- Brian Kernighan
        let mut ans = vec![0i32; (n + 1) as usize];
        for i in 1..=(n as usize) {
            let mut count = 0;
            let mut x     = i;
            while x != 0 {
                x &= x - 1;
                count += 1;
            }
            ans[i] = count;
        }
        ans
        */
    }
}
