class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        """
        Approach:
        1. Sorting -- T.C: O(N log N), S.C: O(1)
             - Sort intervals by start time, check overlap between adjacent intervals.
        2. Brute Force -- T.C: O(N^2), S.C: O(1)
             - Compare every pair of intervals for overlap.
        """

        # Approach 1 -- Sorting
        if len(intervals) <= 1:
            return True

        intervals.sort()

        for i in range(1, len(intervals)):
            if intervals[i][0] < intervals[i - 1][1]:
                return False

        return True

        # Approach 2 -- Brute Force
        # n = len(intervals)
        # for i in range(n):
        #     for j in range(i + 1, n):
        #         if not (intervals[i][1] <= intervals[j][0] or intervals[j][1] <= intervals[i][0]):
        #             return False
        # return True
