/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
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
    int strStr(string haystack, string needle)
    {
        /*
        Approach 1: Use library function find()
        Approach 2: Sliding Window
        */

        // Approach 1
        int ans = 0;
        if (needle.size() == 0)
            return ans;
        ans = haystack.find(needle);
        if (ans != string::npos)
            return ans;
        return -1;

        /* Approach 2
        if (haystack.size() < needle.size())
            return -1;
        if (needle.size() == 0 || haystack == needle)
            return 0;
        string t;
        int i = 0, j = 0, n = haystack.size();
        while (j < n)
        {
            t.push_back(haystack[j]);
            if (j < needle.size() - 1)
                j++;
            else
            {
                if (t == needle)
                    return i;
                t.erase(0, 1);
                i++;
                j++;
            }
        }
        return -1;
        */
    }
};
// @lc code=end
