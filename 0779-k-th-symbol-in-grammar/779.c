int kthGrammar(int n, int k) {
  /* Approach:
     1. [Recursion] -- T.C: O(N), S.C: O(N)
     2. [Math] -- T.C: (log K), S.C: O(1)
  */

  // Appraoch 2: Math - number of set bits in (k - 1)
  // #include <stdio.h> <-- Required with driver
  int cnt = __builtin_popcount(k - 1);
  return cnt % 2 == 0 ? 0 : 1;

  /* Approach 1: Recursion
  if (n == 1 && k == 1)
    return 0;
  int mid = 1 << (n - 2);
  if (k <= mid)
    return kthGrammar(n - 1, k);
  return 1 - kthGrammar(n - 1, k - mid);
  */
}
