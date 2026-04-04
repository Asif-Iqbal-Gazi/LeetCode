impl Solution {
    pub fn can_attend_meetings(mut intervals: Vec<Vec<i32>>) -> bool {
        /*
         * Approach:
         * 1. Sorting -- T.C: O(N log N), S.C: O(1)
         *      - Sort intervals by start time, check overlap between adjacent intervals.
         * 2. Brute Force -- T.C: O(N^2), S.C: O(1)
         *      - Compare every pair of intervals for overlap.
         */

        // Approach 1 -- Sorting
        if intervals.len() <= 1 {
            return true;
        }

        intervals.sort();

        for i in 1..intervals.len() {
            if intervals[i][0] < intervals[i - 1][1] {
                return false;
            }
        }

        true

        /* Approach 2 -- Brute Force
        let n = intervals.len();
        for i in 0..n {
            for j in i + 1..n {
                if !(intervals[i][1] <= intervals[j][0] || intervals[j][1] <= intervals[i][0]) {
                    return false;
                }
            }
        }
        true
        */
    }
}
