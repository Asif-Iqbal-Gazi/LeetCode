/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {
  /* Approach:
   *   1. [Simulation] -- T.C: O(M * N), S.C: O(1), excluding result
   *       - Simulate traversal in the sequence: right --> down --> left -->
   * up.
   *       - Maintain four bounds (up, down, left, right) that shrink inward
   * as we complete each layer.
   *       - Traverse in the current direction until hitting the boundary,
   * then change direction.
   */

  int left  = 0;
  int right = *matrixColSize - 1;
  int up    = 0;
  int down  = matrixSize - 1;

  int curr_row = 0;
  int curr_col = 0;

  int  index     = 0;
  int  direction = 0;
  int *res       = (int *)malloc((right + 1) * (down + 1) * sizeof(int));
  *returnSize    = (right + 1) * (down + 1);

  while (left <= right && up <= down) {
    if (direction == 0) {
      // Traverse right
      for (int i = left; i <= right; i++) {
        res[index++] = matrix[up][i];
      }
      // Change direction to down
      direction = 1;
      up++;
    } else if (direction == 1) {
      // Traverse down
      for (int i = up; i <= down; i++) {
        res[index++] = matrix[i][right];
      }
      // Change direction to left
      direction = 2;
      right--;
    } else if (direction == 2) {
      // Traverse left
      for (int i = right; i >= left; i--) {
        res[index++] = matrix[down][i];
      }
      // Change direction to up
      direction = 3;
      down--;
    } else {
      // Traverse up
      for (int i = down; i >= up; i--) {
        res[index++] = matrix[i][left];
      }
      // Change direction to right
      direction = 0;
      left++;
    }
  }
  return res;
}
