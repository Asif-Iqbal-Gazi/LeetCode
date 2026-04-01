int findNumbers(int *nums, int numsSize) {
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int digitCount = 0;
        int curr       = nums[i];

        while (curr) {
            digitCount++;
            curr /= 10;
        }
        if (digitCount % 2 == 0)
            count++;
    }
    return count;
}
