/** Definition for a binary tree node.
 * struct TreeNode {
 *   int              val;
 *   struct TreeNode *left;
 *   struct TreeNode *right;
 * };
 */

// Dynamic array to store trees
typedef struct {
  struct TreeNode **data;
  int               size;
  int               capacity;
} TreeList;

void initTreeList(TreeList *list) {
  list->capacity = 8;
  list->size     = 0;
  list->data     = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * list->capacity);
}

void addTree(TreeList *list, struct TreeNode *tree) {
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->data = realloc(list->data, sizeof(struct TreeNode *) * list->capacity);
  }
  list->data[list->size++] = tree;
}

struct TreeNode *newNode(int val) {
  struct TreeNode *node = malloc(sizeof(struct TreeNode));
  node->val             = val;
  node->left            = NULL;
  node->right           = NULL;
  return node;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
TreeList buildAllTrees(int start, int end) {
  TreeList list;
  initTreeList(&list);

  // Base Case: no nodes in this range
  if (start > end) {
    addTree(&list, NULL);
    return list;
  }

  for (int i = start; i <= end; i++) {
    TreeList leftTrees  = buildAllTrees(start, i - 1);
    TreeList rightTrees = buildAllTrees(i + 1, end);

    for (int l = 0; l < leftTrees.size; l++) {
      for (int r = 0; r < rightTrees.size; r++) {
        struct TreeNode *root = newNode(i);
        root->left            = leftTrees.data[l];
        root->right           = rightTrees.data[r];
        addTree(&list, root);
      }
    }

    free(leftTrees.data);
    free(rightTrees.data);
  }

  return list;
}

struct TreeNode **generateTrees(int n, int *returnSize) {
  /* Approach:
     1. [Recursion] -- T.C: O(n * C(n)), S.C: O(n * C(n)); C(n): nth Catalan Number
  */
  TreeList result = buildAllTrees(1, n);
  *returnSize     = result.size;
  return result.data;
}
