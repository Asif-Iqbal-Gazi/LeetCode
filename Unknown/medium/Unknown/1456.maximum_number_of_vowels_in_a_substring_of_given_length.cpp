/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution
{
private:
    bool isVowel(const char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(string s, int k)
    {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        int l = 0;
        int r = 0;
        int n = s.size();

        int ans = 0;
        int curr = 0;

        while (r < n)
        {
            if (isVowel(s[r]))
                curr++;
            r++;
            if (r - l == k)
            {
                ans = max(ans, curr);
                if (isVowel(s[l]))
                    curr--;
                l++;
            }
        }

        return ans;
    }
};
// @lc code=end
