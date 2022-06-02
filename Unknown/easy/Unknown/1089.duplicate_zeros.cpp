/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
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
    void duplicateZeros(vector<int> &arr)
    {
        /*Approach: Take pointers in both extreme, when first pointer encounters a zero, insert a new zero and increment first pointer by 2 and pop_back() the last element*/
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (!arr[l])
            {                                   // Found a '0'
                arr.insert(arr.begin() + l, 0); // Insert a new zero
                arr.pop_back();                 // Discard the last element to maintain the array size
                l += 2;                         // Increment the left counter by 2
            }
            else
            {
                l++;
            }
        }
    }
};
// @lc code=end
