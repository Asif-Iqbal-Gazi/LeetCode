/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
class Solution {
   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        int n = answerKey.size();
        int r = 0, l1 = 0, l2 = 0, dupK = k;

        for (r = 0; r < n; r++) {
            k -= answerKey[r] != 'T';
            dupK -= answerKey[r] == 'T';

            if (k < 0) k += answerKey[l1++] != 'T';
            if (dupK < 0) dupK += answerKey[l2++] == 'T';
        }
        return r - min(l1, l2);
    }
};
// @lc code=end
