impl Solution {
    pub fn get_sum(a: i32, b: i32) -> i32 {
        /*
         * Approach:
         * 1. Iterative -- T.C: O(1), S.C: O(1)
         *      - XOR gives sum without carry.
         *        AND shifted left gives carry.
         *        Repeat until carry is zero.
         * 2. Recursive -- T.C: O(1), S.C: O(1)
         *      - Same logic, base case when b == 0.
         */

        // Approach 1 -- Iterative
        let mut a = a;
        let mut b = b;
        while b != 0 {
            let carry = ((a & b) as u32) << 1;
            a         = a ^ b;
            b         = carry as i32;
        }
        a

        /* Approach 2 -- Recursive
        if b == 0 {
            return a;
        }
        Self::get_sum(a ^ b, (((a & b) as u32) << 1) as i32)
        */
    }
}
