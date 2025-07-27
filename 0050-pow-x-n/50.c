double myPow(double x, int n) {
  // Binary Exponentiation -- T.C: O(log N), S.C: O(1)
  long long N = n;
  if (N < 0) {
    x = 1.0 / x;
    N = -N;
  }

  double res = 1;
  while (N) {
    if (N % 2)
      res *= x;
    x *= x;
    N /= 2;
  }
  return res;
}
