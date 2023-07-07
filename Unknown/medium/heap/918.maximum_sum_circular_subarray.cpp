/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        /* Approach:
            1. Kadane's Algorithm -- T.C: O(n), S.C: O(n)
            2. Constant Space -- T.C: O(n), S.C: 0(1)
        */

        // Approach 3
        int n = nums.size();
        int totalSum = 0;
        int maxNonCircularSum = INT_MIN;
        int minNonCircularSum = INT_MAX;
        int minCurrSum = 0;
        int maxCurrSum = 0;

        int i = -1;
        while (++i < n)
        {
            totalSum += nums[i];
            minCurrSum += nums[i];
            maxCurrSum += nums[i];
            minNonCircularSum = min(minCurrSum, minNonCircularSum);
            maxNonCircularSum = max(maxCurrSum, maxNonCircularSum);

            if (minCurrSum > 0)
                minCurrSum = 0;
            if (maxCurrSum < 0)
                maxCurrSum = 0;
        }

        if (minNonCircularSum == totalSum)
            return maxNonCircularSum;
        return max(maxNonCircularSum, totalSum - minNonCircularSum);

        /* Approach 2
        int n = nums.size();
        int totalSum = 0;
        int nonCircularMaxSum = INT_MIN;
        int nonCircularMinSum = INT_MAX;
        int minCurr, minPrev, maxCurr, maxPrev;

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
            minCurr = min(nums[i], nums[i] + (i == 0 ? 0 : minPrev));
            maxCurr = max(nums[i], nums[i] + (i == 0 ? 0 : maxPrev));
            nonCircularMaxSum = max(maxCurr, nonCircularMaxSum);
            nonCircularMinSum = min(minCurr, nonCircularMinSum);
            minPrev = minCurr;
            maxPrev = maxCurr;
        }

        int maxCircularSum = totalSum - nonCircularMinSum;
        if(maxCircularSum == 0) maxCircularSum = INT_MIN;
        return max(nonCircularMaxSum, maxCircularSum);
        */

        /* Approach 1
        int n = nums.size();
        vector<int> dp(n, 0);

        int nonCircularMax = INT_MIN;

        for(int i = 0; i < n; i++) {
            int sum1 = nums[i] + (i == 0 ? 0 : dp[i - 1]);
            int sum2 = nums[i];
            dp[i] = max(sum1, sum2);    // dp[i]: Max subarray sum ending at index i
            nonCircularMax = max(dp[i], nonCircularMax);
        }

        int totalSum = 0;
        int minSum = INT_MAX;
        for(int i = 0; i < n; i++) {
            int sum1 = nums[i] + (i == 0 ? 0 : dp[i - 1]);
            int sum2 = nums[i];
            dp[i] = min(sum1, sum2);    // dp[i]: Min subarray sum ending at index i
            minSum = min(dp[i], minSum);
            totalSum += nums[i];
        }

        int maxCircularSum = totalSum - minSum;


        Case 1: All elements +ve
                nonCircularMax is the answer
        Case 2: Some +ve and some -ve
                totalSum - minSum is the answer
        Case 3: All elements -ve
                maxCircularSum will become 0 <--- No elements taken case
                nonCircularMax will be negative <--- Should be answer

        if(maxCircularSum == 0) maxCircularSum = INT_MIN;
        return max(maxCircularSum, nonCircularMax);
        */
    }
};
// @lc code=end
