
private:
// Builds the LPS (Longest Prefix Suffix) array for KMP
vector<int> computeLPS(const string& pattern) {
  int         m = pattern.size();
  vector<int> lps(m, 0);
  int         len = 0; // Length of the previous longest prefix suffix

  for (int i = 1; i < m;) {
    if (pattern[i] == pattern[len]) {
      lps[i++] = ++len;
    } else {
      if (len != 0) {
        len = lps[len - 1]; // Fall back
      } else {
        lps[i++] = 0;
      }
    }
  }
  return lps;
}

public:
int strStr(const string& haystack, const string& needle) {
  /*
   * Approach 2: Brute Force
   *   - Time Complexity: O(n * m)
   *   - Space Complexity: O(1)
   *
   * Approach 1: KMP Algorithm
   *   - Time Complexity: O(n + m)
   *   - Space Complexity: O(m)
   *
   */

  /* Approach 3 - Using library funciton find()
  int ans = 0;
  if (needle.size() == 0) return ans;
  ans = haystack.find(needle);
  if (ans != string::npos)
      return ans;
  return - 1;
  */

  // Approach 2 -- KMP Algorithm
  int n = haystack.size();
  int m = needle.size();

  if (m == 0)
    return 0; // Edge case: empty needle

  vector<int> lps = computeLPS(needle);
  int         i = 0, j = 0;

  while (i < n) {
    if (haystack[i] == needle[j]) {
      i++;
      j++;
      if (j == m)
        return i - m; // Match found
    } else if (j > 0) {
      j = lps[j - 1];
    } else {
      i++;
    }
  }

  /* Approach 1 -- Bruteforce
  int m = needle.size();
  int n = haystack.size();

  for (int i = 0; i <= n - m; i++) {
    int j = 0;
    while (j < m && haystack[i + j] == needle[j]) {
      j++;
    }
    if (j == m)
      return i;
  }
  */

  return -1; // Not found
}
}
;
