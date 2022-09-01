/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
private:
    // Approach 2
    void solve(int sIndex, vector<int> &nums, vector<vector<int>> &ans)
    {
        // Base Case
        if (sIndex == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = sIndex; i < nums.size(); i++)
        {
            swap(nums[sIndex], nums[i]);
            solve(sIndex + 1, nums, ans);
            swap(nums[sIndex], nums[i]);
        }
    }

    /* Approach 1
    void solve(int n, vector<int> &curr, vector<int> &nums, vector<int> &map, vector<vector<int>> &ans)
    {
        // Base Case
        if (curr.size() == n)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (map[i] == 0)
            {
                map[i] = 1;
                curr.push_back(nums[i]);
                solve(n, curr, nums, map, ans);
                // Backtracking
                curr.pop_back();
                map[i] = 0;
            }
        }
    }
    */

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        /* Approach
            1. Recursion with Map -- T.C: O(n!), S.C: O(N)
            2. Recursion with Swap -- T.C: O(n!), S.C: O(N)
        */

        // Approach 2
        int n = nums.size();
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;

        /* Approach 1
        int n = nums.size();
        vector<int> curr;
        vector<int> map(n, 0);
        vector<vector<int>> ans;
        solve(n, curr, nums, map, ans);
        return ans;
        */
    }
};
// @lc code=end
