/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        /*
        Approach:
        Apply binary search, set 0 as 'low' and letters.size()-1 as 'high', calculate 'mid' and check if letters[mid]<=target, if yes set 'low' to m+1. else set 'high' to m
        */

        int l = 0, h = letters.size() - 1;

        // Some edge cases
        if (target < letters[l] || target >= letters[h])
            return letters[l];

        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (letters[m] > target)
                h = m;
            else
                l = m + 1;
        }
        return letters[l];
    }
};
// @lc code=end
