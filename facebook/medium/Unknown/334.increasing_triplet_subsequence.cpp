/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(n^3), S.C: O(1) -- TLE
            2. Next Greater, Previous Smaller -- T.C: O(n), S.C: O(n)
            3. Optimal -- T.C: O(n), S.C: O(1)
        */

        // Approach 3
        int n = nums.size();
        int first = INT_MAX;
        int second = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= first)
                first = nums[i];
            else if (nums[i] <= second)
                second = nums[i];
            else
                return true;
        }

        return false;

        /* Approach 2
        int n = nums.size();
        // Edge Case
        if(n < 3) return false;

        stack<int> pSt, nSt;
        vector<int> nextGreater(n, INT_MIN);
        vector<int> previousSmaller(n, INT_MAX);

        for(int i = 0; i < n; i++) {            // O(n)
            while(!pSt.empty() && pSt.top() >= nums[i])
                pSt.pop();
            if(!pSt.empty())
                previousSmaller[i] = pSt.top();
            pSt.push(nums[i]);
        }

        for(int i = n - 1; i >= 0; i--) {       // O(n)
            while(!nSt.empty() && nSt.top() <= nums[i])
                nSt.pop();
            if(!nSt.empty())
                nextGreater[i] = nSt.top();
            nSt.push(nums[i]);
        }

        for(int i = 1; i < n - 1; i++) {        // O(n)
            if(nums[i] > previousSmaller[i] && nums[i] < nextGreater[i])
                return true;
        }

        return false;
        */

        /* Approach 1
        int n = nums.size();
        // Edge Case
        if(n < 3) return false;

        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] < nums[j] && nums[j] < nums[k])
                        return true;
                }
            }
        }

        return false;
        */
    }
};
// @lc code=end
