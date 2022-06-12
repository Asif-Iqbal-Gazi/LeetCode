/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
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
    // Our helper function
    // Returns no of possible subArrays with minimum sum less than equal 'k'
    int noOfPossibleSubArray(vector<int> &nums, int k)
    {
        int sum = 0, count = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > k)
            {
                count++;
                sum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int> &nums, int m)
    {
        /* Approach: Binary Search
        1. We will lowest possible sum of the subarry is possible when it contains one element
        2. The highest possible sum will be sum of all the elements.
        3. Thus, we will perform bianry search on this range.
        */

        // Low (Using max_element iterator)
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = noOfPossibleSubArray(nums, mid);
            if (count > m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
// @lc code=end
