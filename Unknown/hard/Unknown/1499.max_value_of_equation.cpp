/*
 * @lc app=leetcode id=1499 lang=cpp
 *
 * [1499] Max Value of Equation
 */

// @lc code=start
class Solution {
   public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        /* Approach:
            1. Sliding Window (Priority Queue) -- T.C: O(N log N), S.C: O(N)
            2. Sliding Window (Montonic Queue) -- T.C: O(N), S.C: O(N)
        */

        /* Intuition:
            -- points are sorted on non-decreasing order, based on xi
            -- We need to consider pair of points that are valid to constraints: |xi - xj| <= k.
            -- If we traverse from left to right:
                yi + yj + |xi - xj| = yi + yj + (xj - xi)
                                    = yi - xi + yj + xj
            -- With these information we can use sliding window technique
        */

        // Approach 2 -- Sliding Window (Monotonic Queue)
        int n = points.size();
        int r = 0, ans = INT_MIN;

        deque<pair<int, int>> dq;
        for (r = 0; r < n; r++) {
            while (!dq.empty() && points[r][0] - dq.front().second > k)
                dq.pop_front();
            if (!dq.empty())
                ans = max(ans, dq.front().first + points[r][0] + points[r][1]);
            while (!dq.empty() && dq.back().first + points[r][0] < points[r][1])
                dq.pop_back();
            dq.push_back({points[r][1] - points[r][0], points[r][0]});
        }

        return ans;

        /* Approach 1 -- Sliding Window (Priority Queue)
        int n = points.size();
        int l = 0, r = 0, ans = INT_MIN;

        priority_queue<pair<int, int>> pq;
        for (r = 0; r < n; r++) {
            while(!pq.empty() && points[r][0] - pq.top().second > k)
                pq.pop();
            if (!pq.empty()) ans = max(ans, pq.top().first + points[r][0] + points[r][1]);
            pq.push({points[r][1] - points[r][0], points[r][0]});
        }

        return ans;
        */
    }
};
// @lc code=end
