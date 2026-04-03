impl Solution {
    pub fn hamming_weight(n: i32) -> i32 {
        /*
         * Approach:
         * 1. Bit Shift -- T.C: O(1), S.C: O(1)
         *      - Check each of the 32 bits one at a time by extracting the
         *        LSB with n & 1, then right shifting n by 1.
         * 2. Brian Kernighan's Algorithm -- T.C: O(k), S.C: O(1)
         *      - n & (n - 1) clears the lowest set bit of n.
         *        Repeat until n is zero, counting iterations.
         *        Only iterates as many times as there are set bits.
         *        k = number of set bits.
         */

        // Approach 2 -- Brian Kernighan
        let mut n = n;
        let mut count = 0;
        while n != 0 {
            n &= n - 1;
            count += 1;
        }
        count

        // Approach 1 -- Bit Shift
        // let mut n = n;
        // let mut count = 0;
        // while n != 0 {
        //     count += n & 1;
        //     n >>= 1;
        // }
        // count
    }
}
