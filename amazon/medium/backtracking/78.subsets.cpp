/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    void findSubsets(int i, int n, vector<int> &temp, vector<int> &nums, vector<vector<int>> &res)
    {
        // Base Case
        if (i == n)
        {
            res.push_back(temp);
            return;
        }

        findSubsets(i + 1, n, temp, nums, res);
        temp.push_back(nums[i]);
        findSubsets(i + 1, n, temp, nums, res);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        /* Approach:
            1. Recursion -- T.C: O()
        */
        int n = nums.size();
        if (n == 1)
            return {{}, nums};

        vector<int> subset;
        vector<vector<int>> res;
        findSubsets(0, n, subset, nums, res);
        return res;
    }
};
// @lc code=end
