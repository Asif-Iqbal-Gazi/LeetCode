class Solution {
public:
  vector<int> getRow(int rowIndex) {
    /* Approach:
     *   1. [Dynamic Programming, Bottom-up] -- T.C: O(N^2), S.C: O(N)
     *      - Initialize result vector of size rowIndex+1 with 1's
     *      - For each row, update elements in-place from right to left:
     *          res[i] = res[i] + res[i-1]
     *      - Return res after building up to rowIndex
     */

    vector<int> res(rowIndex + 1, 1);
    for (int i = 2; i <= rowIndex; i++) {
      for (int j = i - 1; j > 0; j--) {
        res[j] += res[j - 1];
      }
    }
    return res;
  }
};
