/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
  *returnSize        = numRows;
  *returnColumnSizes = (int *)malloc(numRows * sizeof(int));
  int **triangle     = (int *)malloc(numRows * sizeof(int *));

  for (int row = 0; row < numRows; row++) {
    // Each row has (row + 1) elements
    (*returnColumnSizes)[row] = row + 1;
    // Allocate space for the current row
    triangle[row] = (int *)malloc((row + 1) * sizeof(int));

    // First and last elements of each row are always 1
    triangle[row][0]   = 1;
    triangle[row][row] = 1;

    // Fill inner elements
    for (int col = 1; col < row; col++) {
      triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
    }
  }
  return triangle;
}
