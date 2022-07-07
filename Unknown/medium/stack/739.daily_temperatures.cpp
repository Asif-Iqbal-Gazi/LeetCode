/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        /* Approach:
        1. Bruteforce -- T.C: O(N^2), S.C: O(1)
        2. Stack-- O(N), S.C: O(N)
        */

        // Approach 2
        int n = temperatures.size();

        stack<int> st;
        vector<int> ans(n, 0);

        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;

        /* Approach 1 -- Gets TLE
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    ans[i] = (j - i);
                    break;
                }
            }
        }
        return ans;
        */
    }
};
// @lc code=end
