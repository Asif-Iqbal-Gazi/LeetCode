#include <string.h>
char *addBinary(char *a, char *b) {
  int   len_a     = strlen(a);
  int   len_b     = strlen(b);
  int   total_len = (len_a > len_b ? len_a : len_b) + 2; // +1 for possible carry
  char *res       = (char *)malloc(total_len);
  int   sum       = 0;
  int   pos       = total_len - 1;

  // Add the null byte
  res[pos] = '\0';

  while (len_a > 0 || len_b > 0 || sum > 0) {
    if (len_a > 0)
      sum += a[--len_a] - '0';
    if (len_b > 0)
      sum += b[--len_b] - '0';
    res[--pos] = (sum % 2) + '0';
    sum /= 2;
  }

  // 1 byte leak ?
  if (pos > 0)
    memmove(res, res + pos, total_len - pos);
  return res;
}
