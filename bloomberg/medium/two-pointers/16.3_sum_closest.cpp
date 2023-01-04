/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N^3), S.C: O(1)
            2. Sort + 2 Pointers -- T.C: O(N^2), S.C: O(1)
        */

        /* Approach 1
        int ans = INT_MAX;
        int diff = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int currSum = nums[i] + nums[j] + nums[k];
                    int currDiff = abs(target - currSum);
                    if (currDiff < diff)
                    {
                        ans = currSum;
                        diff = currDiff;
                    }
                }
            }
        }
        return ans;
        */

        // Approach 2
        int ans = INT_MAX;
        int diff = INT_MAX;
        int n = nums.size();

        // Sort
        sort(nums.begin(), nums.end());

        // Select the first
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                int currSum = nums[i] + nums[l] + nums[r];
                int currDiff = abs(target - currSum);
                if (currSum == target)
                    return target;
                else if (currSum < target)
                    l++;
                else
                    r--;
                if (currDiff < diff)
                {
                    diff = currDiff;
                    ans = currSum;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
