/* comparator for qsort */
int cmp(const void *a, const void *b) {
    int *i1 = *(int **)a;
    int *i2 = *(int **)b;
    return i1[0] - i2[0];
}

bool canAttendMeetings(int **intervals, int intervalsSize, int *intervalsColSize) {
    /*
     * Approach:
     * 1. Sorting -- T.C: O(N log N), S.C: O(1)
     *      - Sort intervals by start time, check overlap between adjacent intervals.
     * 2. Brute Force -- T.C: O(N^2), S.C: O(1)
     *      - Compare every pair of intervals for overlap.
     */

    // Approach 1 -- Sorting
    if (intervalsSize <= 1)
        return true;

    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < intervals[i - 1][1])
            return false;
    }

    return true;

    /* Approach 2 -- Brute Force
    for (int i = 0; i < intervalsSize; i++) {
        for (int j = i + 1; j < intervalsSize; j++) {
            if (!(intervals[i][1] <= intervals[j][0] || intervals[j][1] <= intervals[i][0]))
                return false;
        }
    }
    return true;
    */
}
