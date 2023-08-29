/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        /* Approach:
            1. Linear Iteration -- T.C: O(n), S.C: O(1)
        */

        vector<string> ans(n);

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) ans[i - 1] += "Fizz";
            if (i % 5 == 0) ans[i - 1] += "Buzz";
            if (ans[i - 1].empty()) ans[i - 1] += to_string(i);
        }

        return ans;
    }
};
// @lc code=end
