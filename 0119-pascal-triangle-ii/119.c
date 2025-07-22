/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize) {
  *returnSize = rowIndex + 1;
  int *res    = (int *)malloc(sizeof(int) * (*returnSize));

  for (int i = 0; i <= rowIndex; i++) res[i] = 1;

  for (int i = 2; i <= rowIndex; i++) {
    for (int j = i - 1; j > 0; j--) {
      res[j] += res[j - 1];
    }
  }
  return res;
}
