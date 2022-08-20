/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        /* Approach :
            1. Bruteforce -- T.C: O(N^3), S.C: O(1) -- Gets TLE
            2. Bruteforce Optimised -- T.C: O(N^2), S.C: O(1) -- Gets TLE
            3. Kadane's Algorithm -- T.C: O(N), S.C: O(1)
        */

        /* Approach 1
        int n = nums.size();
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                currSum = 0;
                for(int k=i; k<=j; k++){
                    currSum += nums[k];
                }
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
        */

        /* Approach 2
        int n = nums.size();
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int i=0; i<n; i++){
            currSum = 0;
            for(int j=i; j<n; j++){
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
        */

        // Approach 3
        int currSum = 0;
        int maxSum = nums[0];

        for (auto x : nums)
        {
            currSum += x;
            maxSum = max(currSum, maxSum);
            if (currSum < 0)
                currSum = 0; // We don't wanna start with a negative number
        }
        return maxSum;
    }
};
// @lc code=end
