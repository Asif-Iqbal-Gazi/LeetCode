/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */

// @lc code=start
class Solution {
   public:
    int reductionOperations(vector<int>& nums) {
        /* Approach:
            1. Sort + Linear Traversal -- T.C: O(N * log N), S.C: O(1)
        */

        // Approach 1 -- Linear Traversal
        /* Idea:
            - After the operation(s) all elements will be equal to the smallest element
            - Take a close look at the example:
                e.g: [1, 1, 2, 2, 3]
                Here smallest is 1, so 3 elements (2, 2, 3) needs to be converted to 1
            - Now, for segment [2, 2, 3] smallest is 2, so only 3 needs to converted to 2
            - Final answer: 3 + 1
        */

        // Sort
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) continue;
            ans += n - i;
        }
        return ans;
    }
};
// @lc code=end
