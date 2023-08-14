/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        /* Approach:
            1. Using Priority Queue -- T.C: O(n log k), S.C: O(k)
        */

        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            if (pq.size() < k)
                pq.push(nums[i]);
            else if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};
// @lc code=end
