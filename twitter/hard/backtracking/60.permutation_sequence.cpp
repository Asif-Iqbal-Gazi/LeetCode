/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution
{
public:
    /* Approach 1
    void findPermutations(int index, string &nums, vector<string> &res)
    {
        // Base Case:
        if (index == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            findPermutations(index + 1, nums, res);
            swap(nums[i], nums[index]);
        }
    }
    */
    string getPermutation(int n, int k)
    {
        /* Approach:
            1. Bruteforce (Backtracking) -- T.C: O(n!*log(n!)), S.C: O(n!) -- GETS TLE
            2. Mathematical -- T.C: O(N^2), S.C: O(N)
        */

        /*
        string nums = "";
        for (int i = 1; i < n + 1; i++)
            nums += to_string(i);

        vector<string> res;
        findPermutations(0, nums, res);
        // Sort res
        sort(res.begin(), res.end());
        return res[k - 1];
        */

        // Approach 2
        int fact = 1;
        vector<int> nums(n, 1);
        for (int i = 1; i < n; i++)
        {
            nums[i] = i + 1;
            fact *= i;
        }
        // Update k to zero based index
        k -= 1;
        string ans = "";
        while (true)
        {
            ans += to_string(nums[k / fact]);
            // Remove selected number from nums
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
                break;
            k %= fact;           // Update K
            fact /= nums.size(); // Update fact
        }
        return ans;
    }
};
// @lc code=end
