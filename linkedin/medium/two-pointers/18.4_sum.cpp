/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N^4), S.C: O(N)
            2. Sort + Two Pointers -- T.C: O(N^3), S.C: O(1)
        */

        // Approach 2
        int n = nums.size();
        if (n < 4)
            return {};
        // Sort
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n - 3; i++)
        {
            // Avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                // Avoid duplicate
                if (j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                long long leftTarget = target;
                leftTarget -= nums[i];
                leftTarget -= nums[j];
                // Two Pointer Approach Now
                int l = j + 1;
                int r = n - 1;
                while (l < r)
                {
                    long long rightTarget = nums[l];
                    rightTarget += nums[r];
                    if (leftTarget < rightTarget)
                        r--;
                    else if (leftTarget > rightTarget)
                        l++;
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    // Remove duplicate from left
                    while (l < r && l > (j + 1) && nums[l] == nums[l - 1])
                        l++;
                    // Remove duplicate from right
                    while (l < r && r < (n - 1) && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        return res;

        /* Approach 1
        int n = nums.size();
        if (n < 4)
            return {{}};
        unordered_set<string> set;
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] != target)
                            continue;
                        string seed = "";
                        seed += to_string(nums[i]);
                        seed += to_string(nums[j]);
                        seed += to_string(nums[k]);
                        seed += to_string(nums[l]);
                        if (set.find(seed) == set.end())
                            res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        set.insert(seed);
                    }
                }
            }
        }
        return res;
        */
    }
};
// @lc code=end
