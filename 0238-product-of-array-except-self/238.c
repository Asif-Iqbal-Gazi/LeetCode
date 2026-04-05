/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    /*
     * Approach:
     * 1. Brute Force                    -- T.C: O(N^2), S.C: O(1)
     *      - For each element, multiply all others.
     * 2. Prefix + Suffix Arrays         -- T.C: O(N),   S.C: O(N)
     *      - Build prefix and suffix arrays, multiply at each index.
     * 3. Prefix + Suffix Space Optimized -- T.C: O(N),   S.C: O(1)
     *      - Use output array for prefix pass, running suffix for second pass.
     */

    // Approach 3 -- Prefix + Suffix Space Optimized
    *returnSize = numsSize;
    int *ans    = (int *)malloc(numsSize * sizeof(int));

    // Pass 1: fill ans with prefix products
    ans[0] = 1;
    for (int i = 1; i < numsSize; i++) ans[i] = ans[i - 1] * nums[i - 1];

    // Pass 2: multiply running suffix into ans
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }
    return ans;

    /* Approach 2 -- Prefix + Suffix Arrays
    *returnSize   = numsSize;
    int *ans      = (int *)malloc(numsSize * sizeof(int));
    int *prefix   = (int *)malloc(numsSize * sizeof(int));
    int *suffix   = (int *)malloc(numsSize * sizeof(int));
    prefix[0]     = 1;
    suffix[numsSize - 1] = 1;
    for (int i = 1; i < numsSize; i++)
        prefix[i] = prefix[i - 1] * nums[i - 1];
    for (int i = numsSize - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i + 1];
    for (int i = 0; i < numsSize; i++)
        ans[i] = prefix[i] * suffix[i];
    free(prefix);
    free(suffix);
    return ans;
    */

    /* Approach 1 -- Brute Force
    *returnSize = numsSize;
    int *ans    = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int product = 1;
        for (int j = 0; j < numsSize; j++) {
            if (i != j)
                product *= nums[j];
        }
        ans[i] = product;
    }
    return ans;
    */
}
