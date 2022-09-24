/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    /* Approach 1
    void findSubsets(int index, int n, vector<int> &subset, vector<int> &nums, vector<vector<int>> &res)
    {
        // Base Case
        if (index == n)
        {
            res.push_back(subset);
            return;
        }

        // Pick Element at index
        subset.push_back(nums[index]);
        findSubsets(index + 1, n, subset, nums, res);
        subset.pop_back(); // Backtracking

        // Not Pick the Element at index
        // Now if we not picking the element at this index then we need to ignore all of it's repeats
        while ((index + 1) < n && nums[index] == nums[index + 1])
            index++;
        findSubsets(index + 1, n, subset, nums, res);
    }
    */
    // Approach 2
    void findSubsets(int index, int n, vector<int> &subset, vector<int> &nums, vector<vector<int>> &res)
    {
        res.push_back(subset);
        for (int i = index; i < n; i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            findSubsets(i + 1, n, subset, nums, res);
            subset.pop_back(); // Backtracking
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        /* Approach:
            1. Backtracking -- T.C: O(n*2^n), S.C: O(k*2^n); K: avg length of subset
            2. Backtracking(Slight Different Implementation) -- T.C: O(n*2^n), S.C: O(k*2^n); K: avg length of subset
        */

        /* Approach 1
        if (nums.size() == 1)
            return {{}, nums};

        // Sort nums array
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        findSubsets(0, nums.size(), subset, nums, res);
        return res;
        */

        // Approach 2
        if (nums.size() == 1)
            return {{}, nums};

        // Sort the nums array
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        findSubsets(0, nums.size(), subset, nums, res);
        return res;
    }
};
// @lc code=end
