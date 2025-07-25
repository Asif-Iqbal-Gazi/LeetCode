

int fib(int n) {
  if (n <= 1)
    return n;
  int prev      = 1;
  int prev2prev = 0;

  for (int i = 2; i <= n; i++) {
    int curr  = prev2prev + prev;
    prev2prev = prev;
    prev      = curr;
  }
  return prev;
}
