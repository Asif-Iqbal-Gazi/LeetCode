/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
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
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        /*
        Approach 1: Two pointer
        1. Question confirms that there at least one solution guranteed.
        2. So, we take two pointers in both the extreme.
        3. Inside a while loop, we check if sum of the element at our pointers are equal to target
        4. If yes return {i+1, j+1}
        5. If sum is greater, then we decrease right pointer (Sorted non-decreasing array)
        6. If sum is less, then we increase left pointer (Sorted non-decreasing array)
        */

        int i = 0, j = numbers.size() - 1, sum = 0;
        while (true)
        {
            sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i + 1, j + 1};
            else if (sum > target)
                j--;
            else
                i++;
        }
        return {};
    }
};
// @lc code=end
