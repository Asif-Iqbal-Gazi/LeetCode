#include <string.h>
char *longestCommonPrefix(char **strs, int strsSize) {
  int prefix_len = strlen(strs[0]);
  for (int i = 1; i < strsSize; i++) {
    int j = 0;
    int m = strlen(strs[i]);
    while (j < prefix_len && strs[i][j] && strs[i][j] == strs[0][j]) j++;
    prefix_len = j;
    if (prefix_len == 0)
      break;
  }
  char *res = (char *)malloc((prefix_len + 1) * sizeof(char));
  strncpy(res, strs[0], prefix_len);
  res[prefix_len] = '\0';
  return res;
}
