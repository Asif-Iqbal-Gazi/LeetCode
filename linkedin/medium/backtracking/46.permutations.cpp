/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    /* Approach 1
    void findPermutations(int n, vector<int> &curr, vector<int> &nums, vector<int> &map, vector<vector<int>> &res)
    {
        // Base Case
        if (curr.size() == n)
        {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (map[i] == 0)
            {
                map[i] = 1;
                curr.push_back(nums[i]);
                findPermutations(n, curr, nums, map, res);
                // Backtracking
                curr.pop_back();
                map[i] = 0;
            }
        }
    }
    */
    // Approach 2
    void findPermutations(int sInd, vector<int> &nums, vector<vector<int>> &res)
    {
        // Base Case
        if (sInd == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = sInd; i < nums.size(); i++)
        {
            swap(nums[i], nums[sInd]);
            findPermutations(sInd + 1, nums, res);
            swap(nums[i], nums[sInd]); // Backtracking
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        /* Approach
            1. Recursion with Map -- T.C: O(n!), S.C: O(N) (Stack Space + Auxiliary Space)
            2. Recursion with Swap -- T.C: O(n!), S.C: O(N) (Only Stack Space)
        */

        /* Approach 1
        int n = nums.size();
        vector<int> curr;
        vector<int> map(n, 0);
        vector<vector<int>> res;
        findPermutations(n, curr, nums, map, res);
        return res;
        */

        // Approach 2
        vector<vector<int>> res;
        findPermutations(0, nums, res);
        return res;
    }
};
// @lc code=end
