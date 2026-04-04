class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        /*
         * Approach:
         * 1. Sorting -- T.C: O(N log N), S.C: O(1)
         *      - Sort intervals by start time, check overlap between adjacent intervals.
         * 2. Brute Force -- T.C: O(N^2), S.C: O(1)
         *      - Compare every pair of intervals for overlap.
         */

        // Approach 1 -- Sorting
        if (intervals.size() <= 1)
            return true;

        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }

        return true;

        /* Approach 2 -- Brute Force
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(intervals[i][1] <= intervals[j][0] || intervals[j][1] <= intervals[i][0]))
                    return false;
            }
        }
        return true;
        */
    }
};
