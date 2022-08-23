/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
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
    string longestPalindrome(string s)
    {
        /* Approach:
            Iterate through the string char by char taking that char as middle of palindrome
            Note: Careful about odd and even no of char string
        */

        int n = s.size();
        int maxLen = 0;
        int leftIndex = 0;
        for (int i = 0; i < n; i++)
        {
            // Odd Palindrome
            findLengthNLeftIndex(s, i, i, maxLen, leftIndex);
            // Even Paliandrome
            findLengthNLeftIndex(s, i, i + 1, maxLen, leftIndex);
        }
        return s.substr(leftIndex, maxLen);
    }

private:
    void findLengthNLeftIndex(string s, int l, int r, int &maxLen, int &leftIndex)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                leftIndex = l;
            }
            r++;
            l--;
        }
    }
};
// @lc code=end
