class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    /* Approach:
     *   1. [Horizontal Scanning] -- T.C: O(n * m), S.C: O(1)
     *      - Initialize prefix length as length of first string.
     *      - For each other string, compare characters with first string.
     *      - Shrink the prefix length when mismatch found.
     */
    int n          = strs.size();
    int prefix_len = strs[0].size();

    for (int i = 1; i < n; i++) {
      int j = 0;
      int m = strs[i].size();
      while (j < prefix_len && j < m && strs[i][j] == strs[0][j]) j++;
      prefix_len = j;
      if (prefix_len == 0)
        break;
    }
    return strs[0].substr(0, prefix_len);
  }
};
