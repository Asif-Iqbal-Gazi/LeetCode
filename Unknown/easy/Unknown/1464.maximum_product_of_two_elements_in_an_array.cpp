/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N), S.C:O(1)
            2. Sorting -- T.C: O(n * log(n)), S.C: O(1)
            3. Heap -- T.C: O(N), S.C: O(N)
        */

        // Approach 3
        make_heap(nums.begin(), nums.end()); // T.C: O(n)
        pop_heap(nums.begin(), nums.end());  // T.C: O(log(n))
        return (nums.front() - 1) * (nums.back() - 1);

        /* Approach 2
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
        */

        /* Approach 1
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                res = max(res, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return res;
        */
    }
};
// @lc code=end
