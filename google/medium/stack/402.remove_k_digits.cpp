/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        /* Approach:
            Start from right, whenever a peak is found, remove it.
            1. Using Stack -- T.C: O(n), S.C: O(n)
        */

        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > num[i] && k)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // Have we removed enough
        while (k && !st.empty())
        {
            st.pop();
            k--;
        }

        n = st.size();
        if (!n)
            return "0";

        string ans(n, 'a');
        while (n > 0)
        {
            ans[n - 1] = st.top();
            st.pop();
            n--;
        }

        n = ans.size();
        int leadingZeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != '0')
                break;
            leadingZeros++;
        }

        ans.erase(0, leadingZeros);

        return ans.size() ? ans : "0";
    }
};
// @lc code=end
