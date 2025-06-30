class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    /* Approach:
     *  1. [Simulation] -- T.C: O(N * M), S.C: O(1) excluding output
     *      - Observation: Move up if (row + col) is even, down if it's odd.
     *      - While moving up: row--, col++
     *      - While moving down: row++, col--
     *      - Handle boundaries carefully to avoid index errors.
     */

    int         n = mat.size();
    int         m = mat[0].size();
    vector<int> result(n * m);

    int r = 0, c = 0;
    for (int i = 0; i < n * m; i++) {
      result[i] = mat[r][c];

      if ((r + c) % 2 == 0) {
        // Moving up
        if (c == m - 1) {
          r++;
        } else if (r == 0) {
          c++;
        } else {
          r--;
          c++;
        }
      } else {
        // Moving down
        if (r == n - 1) {
          c++;
        } else if (c == 0) {
          r++;
        } else {
          r++;
          c--;
        }
      }
    }

    return result;
  }
};
