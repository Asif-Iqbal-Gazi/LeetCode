/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
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
    int singleNumber(vector<int> &nums)
    {
        /* Approach:
        1. Bruteforce: O(N^2)
        2. Sorting : O(NlogN)
        3. Unordered Map : O(N), SC: O(N)
        4. XOR Technique : O(N)
        */

        /* Bruteforce
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                else if (nums[i] == nums[j])
                    count++;
            }
            if (count == 1)
                return nums[i];
        }
        return -1;
        */

        /* Sorting
        int n = nums.size();
        // Edge Case, when only 1 element
        if (n == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        // This loop will handle if n is even
        for (int i = 0; i < n - 1; i += 2)
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        // Edge Case, if there are odd number of element
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        return -1;
        */

        /* Unordered Map
        int n = nums.size();
        unordered_map<int, int> m;
        for (int x : nums)
            m[x]++;
        for (auto x : m)
        {
            if (x.second == 1)
                return x.first;
        }
        return -1;
        */

        // XOR technique
        int n = nums.size();
        int result = nums[0];
        for (int i = 1; i < n; i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};
// @lc code=end
