/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct HashItem {
  int            key;
  int            value;
  UT_hash_handle hh;
};

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  struct HashItem *hashTable = NULL, *item;

  for (int i = 0; i < numsSize; i++) {
    int complement = target - nums[i];
    HASH_FIND_INT(hashTable, &complement, item);
    if (item) {
      int *result = malloc(sizeof(int) * 2);
      result[0]   = item->value;
      result[1]   = i;
      *returnSize = 2;
      // free hash table
      struct HashItem *cur, *tmp;
      HASH_ITER(hh, hashTable, cur, tmp) {
        HASH_DEL(hashTable, cur);
        free(cur);
      }
      return result;
    }
    item        = malloc(sizeof(struct HashItem));
    item->key   = nums[i];
    item->value = i;
    HASH_ADD_INT(hashTable, key, item);
  }
  *returnSize = 0;
  struct HashItem *cur, *tmp;
  HASH_ITER(hh, hashTable, cur, tmp) {
    HASH_DEL(hashTable, cur);
    free(cur);
  }
  return NULL;
}
