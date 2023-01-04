/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        /* Approach:
            1. Compare Left to Right extracting revisions -- T.C: O(max(n,m)), S.C: O(1)
        */

        int n = version1.size();
        int m = version2.size();

        int i = 0;
        int j = 0;

        while (i < n || j < m)
        {
            int n1 = 0;
            int n2 = 0;
            // Extract the revision numbers
            while (i < n && version1[i] != '.')
            {
                n1 = n1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < m && version2[j] != '.')
            {
                n2 = n2 * 10 + (version2[j] - '0');
                j++;
            }
            // Comapre the revision numbers
            if (n1 > n2)
                return 1;
            else if (n1 < n2)
                return -1;
            // Now increment the counters to get pass the '.'
            i++;
            j++;
        }
        return 0;
    }
};
// @lc code=end
