class Solution {
public:
  string reverseWords(string s) {
    /* Approach:
     *  1. [Linear Scan] -- T.C: O(N), S.C: O(N)
     */

    int n = s.size();
    int i = 0;

    while (i < n) {
      int j = i;
      while (j < n && s[j] != ' ') j++;
      reverse(s.begin() + i, s.begin() + j);
      i = j + 1;
    }

    return s;
  }
};
