int missingNumber(int *nums, int numsSize) {
    /* Approach 1: Bit Manipulation -- T.C: O(n), S.C: O(1) */
    int missingNum = numsSize;

    for (int i = 0; i < numsSize; i++) {
        missingNum ^= (i ^ nums[i]);
    }

    return missingNum;
}
