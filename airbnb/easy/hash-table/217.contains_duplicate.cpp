/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        /* Approach :
        1. Bruteforce - O(N^2)
        2. Sorting - O(NlogN)
        3. Unordered Set - O(N) SC : O(N)
        */

        /* Bruteforce
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == nums[i])
                    return true;
            }
        }
        return false;
        */

        /* Sorting
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
        */

        // Using unordered_set
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
