/*
    2815. Max Pair Sum in an Array
    https://leetcode.com/problems/max-pair-sum-in-an-array/description/
*/

class Solution {
   public:
    int maxSum(vector<int>& nums) {
        /* Approach:
            1. Using Map + Bruteforce -- T.C: O(n^2), S.C: O(n)
            2. Above Solution (A little bit optimised) -- T.C: O(n log m), S.C: O(1)
        */

        // Approach 2 -- A little bit optimised
        int n = nums.size();
        int ans = -1, maxDigitNum[10] = {};

        for (int i = 0; i < n; i++) {
            int mDigit = 0, x = nums[i];
            // Get the max digit of the number
            while (x) {  // T.C: O(log m)
                mDigit = max(mDigit, x % 10);
                x /= 10;
            }
            // Update the maxDigitNum array
            if (maxDigitNum[mDigit])
                ans = max(ans, maxDigitNum[mDigit] + nums[i]);
            maxDigitNum[mDigit] = max(maxDigitNum[mDigit], nums[i]);
        }
        return ans;

        /* Approach 1 -- Map + Bruteforce
        int n = nums.size();
        vector<int> maxDigit[10];

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int mDigit = 0;
            while (x) {
                int digit = x % 10;
                x /= 10;
                mDigit = max(mDigit, digit);
            }
            maxDigit[mDigit].push_back(i);
        }
        int ans = -1;
        for (int i = 1; i < 10; i++) {
            int sz = maxDigit[i].size();
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    if (j == k) continue;
                    ans = max(ans, nums[maxDigit[i][j]] + nums[maxDigit[i][k]]);
                }
            }
        }
        return ans;
        */
    }
};