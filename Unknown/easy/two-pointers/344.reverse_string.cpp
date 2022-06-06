/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
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
    void reverseString(vector<char> &s)
    {
        /*
        Approach 1: Using two pointers
        Approach 2: Using library function
        */

        // Approach 1
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(s[i++], s[j--]);
        }
        /* Approach 2
        reverse(s.begin(), s.end());
        */
    }
};
// @lc code=end
