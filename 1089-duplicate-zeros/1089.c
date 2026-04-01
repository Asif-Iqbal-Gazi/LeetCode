void duplicateZeros(int *arr, int arrSize) {
    /*
     * Approach: Two-Pass In-Place
     * T.C: O(N), S.C: O(1)
     *
     * Pass 1 - Find the rightmost surviving element:
     *   Simulate the duplication to determine which element in the original array maps to the last
     *   position in the final array.
     *
     * Pass 2 - Fill from right to left:
     *   Starting from the rightmost sruviving element, copy values backwards into their final
     *   positions, duplicating zeros as we go.
     */

    /* Pass 1: Find the rightmost surviving element */
    int right        = 0;
    int elementCount = 0;
    for (right = 0; right < arrSize; right++) {
        elementCount++;
        if (arr[right] == 0)
            elementCount++;
        if (elementCount >= arrSize)
            break;
    }

    /* No zeros caused an overflow -- array remains unchanged */
    if (right == arrSize - 1)
        return;

    /* Pass 2: Fill from right to left */
    int i = arrSize - 1;

    /*
     * Edge Case: the rightmost surviving element is a zero that sits exactly on the boundary
     * (elementCount overshot to arrSize + 1), meaning only one copy of it fits.
     * Write the signle copy and advance both pointers.
     */
    if (arr[right] == 0 && elementCount > arrSize) {
        arr[i--] = 0;
        right--;
    }

    // [1,5,2,0,6,8,0,6,0]
    while (i >= 0) {
        int val  = arr[right--];
        arr[i--] = val;
        if (val == 0)
            arr[i--] = val;
    }
}
