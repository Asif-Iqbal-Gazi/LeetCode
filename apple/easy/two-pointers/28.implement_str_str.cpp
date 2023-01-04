/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution
{
private:
    vector<int> computeLPS(string needle)
    {
        int m = needle.size();
        int i = 1;
        int prevLPS = 0;
        vector<int> lps(m, 0);

        while (i < m)
        {
            if (needle[i] == needle[prevLPS])
                lps[i++] = ++prevLPS;
            else
            {
                if (prevLPS == 0)
                    i++;
                else
                    prevLPS = lps[prevLPS - 1];
            }
        }
        return lps;
    }

public:
    int strStr(string haystack, string needle)
    {
        /* Approach :
            1. Bruteforce -- T.C: O(n * m), S.C: O(1)
            2. KMP Algo -- T.C: O(n + m), S.C: O(m)
            3. Use library function find()
        */

        /* Approach 3
        int ans = 0;
        // Some sanity check
        if (needle.size() == 0)
            return ans;
        ans = haystack.find(needle);
        if (ans != string::npos)
            return ans;
        return -1;
        */

        // Approach 2
        int m = needle.size();
        if (m == 0)
            return 0;

        int n = haystack.size();
        // Prepare the lps array
        vector<int> lps = computeLPS(needle);

        // KMP Algorithm
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (needle[j] == haystack[i])
                i++, j++;
            else if (j == 0)
                i++;
            else
                j = lps[j - 1];
            // If we have reached the end of needle return
            if (j == m)
                return i - m;
        }
        return -1;

        /* Approach 1
        int m = needle.size();
        if (m == 0)
            return 0;
        int n = haystack.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (needle[j] != haystack[i + j])
                    break;
                if (j == m - 1)
                    return i;
            }
        }
        return -1;
        */
    }
};
// @lc code=end
