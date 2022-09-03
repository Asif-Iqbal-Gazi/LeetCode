/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution
{
private:
    void generatePermutaion(int index, vector<int> &nums, vector<vector<int>> &res)
    {
        if (index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for (int i = index; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
                continue;
            s.insert(nums[i]);
            swap(nums[i], nums[index]); // Normal Swap
            generatePermutaion(index + 1, nums, res);
            swap(nums[i], nums[index]); // Backtracking
        }
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        /* Approach
            1. Bruteforces -- T.C: O(N!), S.C:(N) -- Gets TlE
                First Generate All Unique Permutation.
                Then fidn the given permutation in the permutations.
                Return the next one.
            2. Optimal Method -- T.C: O(N), S.C: O(1)
                Traverse from the back of nums to find the first dip.
                Then again traverse from back to find and element slightly greater than element at dip.
                Swap them, and reverse remaining elements at left
                If there is no dip, reverse them all.
        */

        // Approach 2
        int n = nums.size(), d, r;

        for (d = n - 2; d >= 0; d--)
        {
            if (nums[d] < nums[d + 1])
                break;
        }
        if (d < 0)
        {
            // Complete monotonic increasing from left
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (r = n - 1; r > d; r--)
            {
                if (nums[d] < nums[r])
                    break;
            }
            swap(nums[d], nums[r]);
            reverse(nums.begin() + d + 1, nums.end());
        }

        /* Approach 1
        if (nums.size() == 1)
            return;

        vector<int> seed = nums;
        sort(seed.begin(), seed.end());

        vector<vector<int>> res;
        // Generate all permutation using recursion + Backtracking
        generatePermutaion(0, seed, res);
        int ansIndex = -1;
        bool match = false;
        sort(res.begin(), res.end());
        // Now iterate over res to find our inputs position
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                if (nums[j] == res[i][j])
                    match = true;
                else
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                ansIndex = (i == res.size() - 1) ? 0 : i + 1;
                break;
            }
        }
        // Copy res[ansIndex] to nums
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = res[ansIndex][i];
        }
        */
    }
};
// @lc code=end
