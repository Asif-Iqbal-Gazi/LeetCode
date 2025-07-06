int *computeLPS(char *neddle, int m) {
  int *lps = (int *)malloc(sizeof(int) * m);
  int  len = 0;
  lps[0]   = 0;

  for (int i = 1; i < m;) {
    if (neddle[i] == neddle[len]) {
      lps[i++] = ++len;
    } else if (len != 0) {
      len = lps[len - 1];
    } else {
      lps[i++] = 0;
    }
  }
  return lps;
}

int strStr(char *haystack, char *needle) {
  int n = strlen(haystack);
  int m = strlen(needle);

  if (m == 0)
    return 0;

  int *lps = computeLPS(needle, m);
  int  i   = 0;
  int  j   = 0;

  while (i < n) {
    if (haystack[i] == needle[j]) {
      i++;
      j++;
      if (j == m) {
        free(lps);
        return i - m;
      }
    } else if (j > 0) {
      j = lps[j - 1];
    } else {
      i++;
    }
  }

  free(lps);
  return -1;
}
