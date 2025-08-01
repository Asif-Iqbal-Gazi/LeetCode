class Solution {
public:
  int kthGrammar(int n, int k) {
    /* Approach:
        1. [Recursion] -- T.C: O(n), S.C: O(n)
            - Base Case: first symbol is always 0.
            - Find mid of current row.
            - If k <= mid -> same as previous row.
            - Else -> inverted previous row.
        2. [Math] -- T.C: O(log k), S.C: O(1)
            - Number of of set bits in (k - 1) tells how many times the symbol flipped.
            - Even flips -> 0; odd flips -> 1.
    */

    /* Observation:
        Observe, for n = 4 our rows are:
            0
            0 1
            0 1 1 0
            0 1 1 0 1 0 0 1
        => Each row doubles the previous row.
        => First half of the row = same as previous row.
        => Second half of the row = inverted previous row.
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
