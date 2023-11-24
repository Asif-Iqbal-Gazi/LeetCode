/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
class Solution {
   public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        /* Approach:
            1. Sort arrival time -- T.C: O(N log N), S.C: O(N)
            2. Heap -- T.C: O(N log N), S.C: O(N)
        */

        // Approach 2 -- Heap
        int n = dist.size();
        priority_queue<float, vector<float>, greater<float>> pq;

        for (int i = 0; i < n; i++)
            pq.push((float)dist[i] / speed[i]);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (pq.top() <= i) break;
            pq.pop();
            count++;
        }
        return count;

        /* Approach 1 -- Sort Arrival
        int n = dist.size();
        vector<float> arrival(n);

        // Find all the arrival time
        for (int i = 0; i < n; i++) {           // T.C: O(N)
            arrival[i] = (float)dist[i] / speed[i];
        }

        sort(arrival.begin(), arrival.end());   // T.C: O(N log N)

        int count = 0;
        for (int i = 0; i < n; i++) {           // T.C: O(N)
            if (i  >= arrival[i]) break;
            count++;
        }
        return count;
        */
    }
};
// @lc code=end
