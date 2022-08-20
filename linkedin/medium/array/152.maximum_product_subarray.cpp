/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
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
    int maxProduct(vector<int> &nums)
    {
        /* Approach :
            1. Bruteforce: T.C: O(N^2), S.C: O(1) -- Gets TLE
            2. DP: T.C: O(N), S.C: O(1)
                For a current index the idea is to maintain a curr_max and curr_min upto the previous index.
        */

        /* Approach 1
        int n = nums.size();
        int maxProduct = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int currProduct = 1;
            for (int j = i; j < n; j++)
            {
                currProduct *= nums[j];
                maxProduct = max(maxProduct, currProduct);
            }
        }
        return maxProduct;
        */

        // DP Solution

        int n = nums.size();
        int ans = nums[0];
        int curr_max = ans;
        int curr_min = ans;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(curr_max, curr_min);
            curr_max = max(nums[i], curr_max * nums[i]);
            curr_min = min(nums[i], curr_min * nums[i]);
            ans = max(ans, curr_max);
        }
        return ans;
    }
};
// @lc code=end
