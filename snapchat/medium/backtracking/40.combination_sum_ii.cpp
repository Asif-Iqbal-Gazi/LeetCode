/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    // Approach 2
    void findCombinationSum(int index, int n, int target, vector<int> &ds, vector<int> &nums, vector<vector<int>> &res)
    {
        // Base Case
        if (target == 0)
        {
            res.push_back(ds);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue; // Skip If already considered this number for same index

            if (nums[i] > target)
                break;

            ds.push_back(nums[i]);
            findCombinationSum(i + 1, n, target - nums[i], ds, nums, res);
            ds.pop_back(); // Backtrack
        }
    }
    /* Approach 1
    void findCombinationSum(int index, int n, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &res)
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
        if (candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            findCombinationSum(index + 1, n, target - candidates[index], candidates, ds, res);
            ds.pop_back(); // Backtracking
        }

        // Not pick
        // If we have not picked an element before we should skip that as well
        while ((index + 1) < n && candidates[index] == candidates[index + 1])
            index++;
        findCombinationSum(index + 1, n, target, candidates, ds, res);
    }
    */
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        /* Approach:
            1. Backtracking -- T.C: O(k*2^N), S.C: O(k*2^N)
            2. Backtracking (A different implementation of Recursion) -- T.C: O(n*2^n), S.C: O(k*2^n)
        */

        /* Approach 1
        int n = candidates.size();

        // Sort to avoid duplication
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> res;
        findCombinationSum(0, n, target, candidates, ds, res);
        return res;
        */

        // Approach 2
        int n = candidates.size();
        // Sort to avoid duplication
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> res;
        findCombinationSum(0, n, target, ds, candidates, res);
        return res;
    }
};
// @lc code=end
