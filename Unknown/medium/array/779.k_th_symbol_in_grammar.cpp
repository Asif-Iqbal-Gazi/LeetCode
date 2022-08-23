/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
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
    int kthGrammar(int n, int k)
    {
        /* Approach:
            1. Recursion:
                Observe for n = 4 our rows are as follow:
                0
                0 1
                0 1 1 0
                0 1 1 0 1 0 0 1

                i) Each row doubles
                ii) Each row's first half is same as previous row.
                iii) 2nd Half of each row is inverted of the previous row.

                Thus, if we think of the recursion in terms of smaller input then, if k <= mid then k will remain same
                else, it will be k - mid inverted
        */

        // Base Case
        if (n == 1 && k == 1)
            return 0;

        int mid = pow(2, n - 1) / 2;
        if (k <= mid)
        {
            return kthGrammar(n - 1, k);
        }
        else
        {
            return !kthGrammar(n - 1, k - mid);
        }
    }
};
// @lc code=end
