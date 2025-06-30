/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDiagonalOrder(int **mat, int matSize, int *matColSize, int *returnSize) {
  /* Approach:
   * [Simulation] -- T.C: O(N * M), S.C: O(1)
   * - Observation: Move up if (row + col) is even, down if it's odd.
   * - While moving up: row--, col++
   * - While moving down: row++, col--
   * - Handle boundaries carefuly to avoid index errors.
   */
  int n = matSize;
  int m = *matColSize;

  int *res    = (int *)malloc(n * m * sizeof(int));
  *returnSize = n * m;

  int r = 0, c = 0;
  for (int i = 0; i < n * m; i++) {
    res[i] = mat[r][c];

    if ((r + c) % 2 == 0) {
      // Moving Up
      if (c == m - 1)
        r++;
      else if (r == 0)
        c++;
      else {
        r--;
        c++;
      }
    } else {
      if (r == n - 1)
        c++;
      else if (c == 0)
        r++;
      else {
        r++;
        c--;
      }
    }
  }
  return res;
}
