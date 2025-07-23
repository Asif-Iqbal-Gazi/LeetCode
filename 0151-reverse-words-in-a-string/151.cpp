class Solution {
public:
  string reverseWords(string s) {
    /* Approach:
     *  1. [Linear Scan] -- T.C: O(N), S.C: O(1)
     *      - Remove extra spaces (leading, trailing, and in-between)
     *      - Reverse each word in place.
     *      - Reverse the whole string to get final order.
     */

    int n        = s.size();
    int writePos = 0, i = 0;

    // Remove extra spaces: keep single spaces between words
    while (i < n) {
      if (s[i] != ' ' || (i > 0 && s[i - 1] != ' '))
        s[writePos++] = s[i];
      ++i;
    }

    // Remove trialing space if any
    if (writePos > 0 && s[writePos - 1] == ' ')
      --writePos;
    s.resize(writePos);

    // Reverse each word
    i = 0;
    while (i < writePos) {
      int j = i;
      while (j < writePos && s[j] != ' ') ++j;
      reverse(s.begin() + i, s.begin() + j);
      i = j + 1;
    }

    // Reverse the whole string
    reverse(s.begin(), s.end());

    return s;
  }
};
