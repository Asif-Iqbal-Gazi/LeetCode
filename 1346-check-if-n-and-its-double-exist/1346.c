bool checkIfExist(int *arr, int arrSize) {
    /*
     * Approach:
     * 1. Bruteforce -- T.C: O(n^2), S.C: O(1)
     * 2. Map -- T.C: O(n), S.C: O(1)
     */

    /* Map */
    int freqMap[2001] = {0};

    for (int i = 0; i < arrSize; i++) {
        int x = arr[i];
        if ((2 * x >= -1000 && 2 * x <= 1000 && freqMap[2 * x + 1000]) ||
            ((x % 2 == 0) && freqMap[x / 2 + 1000])) {
            return true;
        }
        freqMap[x + 1000] = 1;
    }
    return false;

    /* BruteForce
    for (int i = 0; i < arrSize; i++) {
        int x = arr[i];
        for (int j = i + 1; j < arrSize; j++) {
            int y = arr[j];
            if (2 * x == y || 2 * y == x)
                return true;
        }
    }
    return false;
    */
}
