/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
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
    // Given a sorted array and k this function will return the count of pairs with difference less than or equal k
    int pairsSmallerThan(vector<int> &nums, int k, int n)
    {
        int j = 0, count = 0;
        for (int i = 1; i < n; i++)
        {
            while (nums[i] - nums[j] > k)
                j++;
            count += (i - j);
        }
        return count;
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {
        /* Approach : Binray Search
        1. Sort the array.
        2. Now max differnece possible nums[n-1] - nums[0] (this is our upper bound 'r')
        3. We iterate over the array to find the minimum by comparing adjacent elements (this is our lower bound 'l')
        4. Then calculate mid and check how many pairs are less than or equal mid.
        5. If it is less than k then update l to m + 1
        6. Else r = m
        7. Once the loop temrinates l == r. So return l
        */

        int n = nums.size();
        // Sort the array
        sort(nums.begin(), nums.end());
        // Find the max and min difference
        int r = nums[n - 1] - nums[0], l = INT_MAX;
        // Update the minimum
        for (int i = 1; i < n; i++)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff < l)
                l = diff;
            if (l == 0)
                break;
        }

        while (l < r)
        {
            int m = l + (r - l) / 2;
            int cnt = pairsSmallerThan(nums, m, n);
            if (cnt < k)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
// @lc code=end
