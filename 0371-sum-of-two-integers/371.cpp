class Solution {
  public:
    int getSum(int a, int b) {
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
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a                  = a ^ b;
            b                  = carry;
        }
        return a;

        /* Approach 2 -- Recursive
        if (b == 0)
            return a;
        return getSum(a ^ b, (unsigned int)(a & b) << 1);
        */
    }
};
