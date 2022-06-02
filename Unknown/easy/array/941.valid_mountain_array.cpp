/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
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
    bool validMountainArray(vector<int> &arr)
    {
        /*
        Approach: Two Pointer
        Take two loops, first will iterate from left most element and breaks if immediate next element is not greater
        Second wil iterate from rightmost element and break if immediate previous element is not greater.
        Finally, if left pointer is non-zero and right point is not n-1 indexed and are equal then return true, else false.
        */

        int i, j, n = arr.size();
        for (i = 0; i < n - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
                break;
        }
        for (j = n - 1; j > 0; j--)
        {
            if (arr[j] >= arr[j - 1])
                break;
        }
        return (i && (j != n - 1) && (i == j)) ? true : false;
    }
};
// @lc code=end
