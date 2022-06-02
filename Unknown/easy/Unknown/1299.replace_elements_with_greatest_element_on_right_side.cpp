/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
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
    vector<int> replaceElements(vector<int> &arr)
    {
        /*Approach:
        Take two pointer/variable rightMax and newMax, now start reverse iteration. Inside the loop first calculate the newMax = max(rightMax, arr[j]), then set arr[j] = rightMax and finally update rightMax = newMax
        */

        int n = arr.size();
        int j = n - 1, rightMax = -1, newMax;
        while (j >= 0)
        {
            newMax = max(rightMax, arr[j]);
            arr[j--] = rightMax;
            rightMax = newMax;
        }
        return arr;
    }
};
// @lc code=end
