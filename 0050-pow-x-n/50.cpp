class Solution {
public:
  double myPow(double x, int n) {
    /* Approach:
       1. [Binary Exponentiation] -- T.C: O(lon N), S.C: O(1)
    */

    long long N = n; // Convert to long long to handle INT_MIN

    if (N < 0) {
      x = 1.0 / x;
      N = -N;
    }

    double res = 1;
    while (N) {
      if (N % 2)
        res *= x;
      x = x * x;
      N /= 2;
    }
    return res;
  }
};
