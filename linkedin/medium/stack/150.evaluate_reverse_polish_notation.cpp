/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
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
    int evalRPN(vector<string> &tokens)
    {
        /* Approach:
        1. Using Stack -- T.C: O(N), S.C: O(N)
        */

        stack<int> st;
        int a = 0, b = 0;

        for (auto c : tokens)
        {
            // The char is a number
            if (c.size() > 1 || isdigit(c[0]))
            {
                st.push(stoi(c));
            }
            else
            {
                // We are dealing with an operator
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                switch (c[0])
                {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(a - b);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push(a / b);
                    break;
                }
            }
        }
        return st.top();
    }
};
// @lc code=end
