#include <stdbool.h>
#include <stdlib.h>

// Simple hash set using open addressing
#define TABLE_SIZE 200003

typedef struct {
    int  key;
    bool occupied;
} Entry;

static int hash(int key) {
    return ((unsigned int)(key + 1000000000)) % TABLE_SIZE;
}

static bool setInsert(Entry *table, int key) {
    int idx = hash(key);
    while (table[idx].occupied) {
        if (table[idx].key == key)
            return false; // already exists
        idx = (idx + 1) % TABLE_SIZE;
    }
    table[idx].key      = key;
    table[idx].occupied = true;
    return true;
}

bool containsDuplicate(int *nums, int numsSize) {
    /*
     * Approach:
     * 1. Brute Force -- T.C: O(N^2), S.C: O(1)
     *      - For each element, check all subsequent elements for a duplicate.
     * 2. Sorting     -- T.C: O(N log N), S.C: O(1)
     *      - Sort the array. Duplicates will be adjacent.
     * 3. Hash Set    -- T.C: O(N),       S.C: O(N)
     *      - Insert each element into a hash set.
     *        If already present, a duplicate is found.
     */

    // Approach 3 -- Hash Set
    Entry table[TABLE_SIZE] = {0};
    for (int i = 0; i < numsSize; i++) {
        if (!setInsert(table, nums[i]))
            return true;
    }
    return false;

    /* Approach 2 -- Sorting
    // qsort helper
    int cmp(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
    */

    /* Approach 1 -- Brute Force
    for (int i = 0; i < numsSize; i++)
        for (int j = i + 1; j < numsSize; j++)
            if (nums[i] == nums[j])
                return true;
    return false;
    */
}
