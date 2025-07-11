class Solution {
public:
  void reverseString(vector<char>& s) {
    /* Approach:
     *   1. [Two Pointer] -- T.C: O(n), S.C: O(1)
     */
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
      char t = s[i];
      s[i]   = s[j];
      s[j]   = t;
      i++;
      j--;
    }
  }
};
