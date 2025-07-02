class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    /* Approach:
     * 1. [Simulation] -- T.C: O(N^2), S.C: O(N^2)
     *    - We construct each row iteratively based on the previous one.
     *    - Base case: First row is always [1].
     *    - For each subsequent row:
     *        - First and last elements are 1.
     *        - Each inner element is the sum of the two elements above it.
     */

    vector<vector<int>> triangle(numRows);
    triangle[0] = {1};
    if (numRows == 1)
      return triangle;

    triangle[1] = {1, 1};
    for (int row = 2; row < numRows; ++row) {
      vector<int> new_row(row + 1, 1); // First and last elements are 1

      // Fill inner elements using previous row
      for (int j = 1; j < row; ++j) {
        new_row[j] = triangle[row - 1][j - 1] + triangle[row - 1][j];
      }

      triangle[row] = new_row;
    }

    return triangle;
  }
};
