int climbStairs(int n) {
  if (n <= 3)
    return n;

  int prev      = 2;
  int prev2prev = 1;
  for (int i = 3; i <= n; i++) {
    int curr  = prev2prev + prev;
    prev2prev = prev;
    prev      = curr;
  }
  return prev;
}
