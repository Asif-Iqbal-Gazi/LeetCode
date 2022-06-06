/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
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
    bool isvowel(char a)
    {
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s)
    {
        /* Approach: Two Pointers */
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (!isvowel(s[i]))
                i++;
            if (!isvowel(s[j]))
                j--;
            if (isvowel(s[i]) && isvowel(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
// @lc code=end
