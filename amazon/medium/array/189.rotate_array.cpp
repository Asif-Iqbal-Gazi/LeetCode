/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
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
    void rotate(vector<int> &nums, int k)
    {
        /*
        Approach:
        1. As k can be greater than array length, calculate new k = k%n.
        2. Now if k is equal to zero or array length return
        3. Reverse the array, then partition the array based on k.
        4. Reverse the partioned arrays and done(Since we will do this in place)
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0, n = nums.size(), j = n - 1;
        k = k % n;
        // Edge cases
        if (k == 0 || k == n)
        {
            return;
        }
        // Reverse the array
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
        // We will make partition now, [0-(k-1)] & [k-(n-1)] and finally reverse them individually in place
        i = 0;
        j = k - 1;
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
        i = k;
        j = n - 1;
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    }
};
// @lc code=end
