/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
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
    int firstBadVersion(int n)
    {
        /*
        Approach:
        1. We will first calculate the mid and check to verify with API.
        2. If 'false', we will update our l = m+1 (As the bad version will be to our right)
        3. However if the API response is 'true' we will update our r=m. (Not m-1, cause this very well might be our first bad version)
        */

        int m = 0, l = 1, r = n;
        while (l < r)
        {
            m = l + (r - l) / 2;
            if (isBadVersion(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end
