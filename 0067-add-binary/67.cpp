class Solution {
public:
  string addBinary(string a, string b) {
    /* Approach:
     * 1. [Simulation] -- T.C: O(max(n, m)), S.C: O(max(n, m))
     *    - Start from the end of both strings
     *    - Keep adding digits and carry
     *    - Preallocate the result string with size = max(len(a), len(b)) + 1
     *    - Fill the result string from the back using a decrementing index.
     *    - At the end, check for a leading '0' and strip it if unused.
     */

    int    i       = a.size() - 1;
    int    j       = b.size() - 1;
    int    sum     = 0;
    int    carry   = 0;
    int    max_len = max(a.size(), b.size()) + 1;
    string res(max_len, '0');
    int    k = max_len - 1;

    while (i >= 0 || j >= 0 || carry) {
      sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';
      res[k--] = (sum % 2) + '0';
      carry    = sum / 2;
    }

    // Remove leading '0' if it wasn't used
    if (res[0] == '0') {
      return res.substr(1);
    }
    return res;
  }
};
