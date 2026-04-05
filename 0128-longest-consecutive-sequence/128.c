int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int longestConsecutive(int *nums, int numsSize) {
    /*
     * Approach:
     * 1. Sorting -- T.C: O(N log N), S.C: O(1)
     *      - Sort and count consecutive elements.
     */

    // Approach 1 -- Hash Set (simulated via sorting fallback in C)
    if (numsSize < 2)
        return numsSize;

    qsort(nums, numsSize, sizeof(int), cmp);

    int longest = 1, curr = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == nums[i - 1] + 1)
            curr++;
        else {
            if (curr > longest)
                longest = curr;
            curr = 1;
        }
    }

    return curr > longest ? curr : longest;
}
