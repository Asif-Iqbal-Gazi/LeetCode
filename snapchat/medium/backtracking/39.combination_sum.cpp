/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    void findCombinationSum(int index, int target, int n, vector<int> &ds, vector<int> &nums, vector<vector<int>> &res)
    {
        // Base Case
        if (target == 0)
        {
            res.push_back(ds);
            return;
        }
        if (index == n)
            return;

        // Pick
        if (nums[index] <= target)
        {
            ds.push_back(nums[index]);
            findCombinationSum(index, target - nums[index], n, ds, nums, res);
            ds.pop_back();
        }

        // Not Pick
        findCombinationSum(index + 1, target, n, ds, nums, res);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        /* Approach:
            1. Backtracking -- T.C: O(k*2^t), S.C: O(k*x)
        */

        // Edge case
        if (target == 1)
            return {};

        vector<int> ds;
        vector<vector<int>> res;
        findCombinationSum(0, target, candidates.size(), ds, candidates, res);
        return res;
    }
};
// @lc code=end
