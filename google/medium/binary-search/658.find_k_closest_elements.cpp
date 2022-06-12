/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
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
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        /*
        Approach:
        1. Here we need a window of k, we will find our lower bound for the window and add k with it to get our upper bound. (But why not choose upper bound and then substract k from it ?? Well, as per question we prefer left bound in case of a tie.)
        2. Also, observe that our 'x' target must lie in our window and our lowerbound will always be less than or equal to at (n-k) position. (Why?? Because, the extreme right it can go is when our target 'x' does not lie in the array is greater than even arr[n-1], we choose the k elements from arr[n-1] towards left)
        3. Observe, x - arr[i] is still sorted. Thus we can find the lower bound using binary search in (0, n-k) range.
        */

        int n = arr.size();
        int l = 0;
        int r = n - k; // This the upper limit of our lower bound of the window

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (x - arr[m] > arr[m + k] - x)
                l = m + 1;
            else
                r = m;
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
// @lc code=end
