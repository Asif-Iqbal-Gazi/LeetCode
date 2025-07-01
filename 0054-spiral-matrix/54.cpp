class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    /* Approach:
     * 1. [Simulation] -- T.C: O(N * M), S.C: O(1)
     *  - Simulate traversal in sequence: right --> down --> left --> up.
     *  - Maintain four bounds (up, down, left, right) that shrinks inward as we complete each
     * layer.
     *  - Traverse in the current direction until hitting the boundary, then change direction.
     */
    int m         = matrix.size();
    int n         = matrix[0].size();
    int up        = 0;
    int left      = 0;
    int right     = n - 1;
    int down      = m - 1;
    int direction = 0;

    int         index = 0;
    vector<int> res(m * n, 0);
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
        // Traverse Down
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
};
