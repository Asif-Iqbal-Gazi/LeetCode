/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
class Solution {
   public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        /* Approach:
            1. Sliding Window using Priority Queue -- T.C: O(n * log k), S.C: O(k)
        */

        // Approach 1
        int n = nums.size();
        auto lambda = [&nums](const pair<int, int> &p1, const pair<int, int> &p2) -> bool {
            return nums[p1.second][p1.first] > nums[p2.second][p2.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lambda)> pq(lambda);

        // Initialize the first iteration
        int left = INT_MAX;
        int right = INT_MIN;
        for (int i = 0; i < n; i++) {  // O(n * log k)
            pq.push({0, i});
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
        }

        int curr_left, curr_right = right;
        while (true) {  // O(n * log k)
            auto [j, i] = pq.top();
            pq.pop();
            j++;
            if (j == nums[i].size() || left == right) break;
            pq.push({j, i});
            curr_right = max(curr_right, nums[i][j]);
            auto [j2, i2] = pq.top();
            curr_left = nums[i2][j2];
            if ((1L * curr_right - 1L * curr_left) < (1L * right - 1L * left))
                left = curr_left, right = curr_right;
        }

        return {left, right};
    }
};
// @lc code=end
