/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
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
    string decodeString(string s)
    {
        /* Approach:
            1. Stack
        */

        string ans = "";
        stack<string> st;

        for (char c : s)
        {
            string x(1, c);
            // Push everything into the stack untill ']' is encountered
            if (c != ']')
                st.push(x);
            else
            {
                string substr = "";
                // Encountered ']', start poping untill '['
                while (st.top() != "[")
                {
                    substr.insert(0, st.top());
                    st.pop();
                }
                // Pop the '[' as well
                st.pop();
                // Getting the multiplier
                int num = 0;
                int multiplier = 1;
                while (!st.empty() && isdigit(st.top()[0]))
                {
                    int curr = st.top()[0] - '0';
                    curr *= multiplier;
                    num += curr;
                    multiplier *= 10;
                    st.pop();
                }
                // Multiply the string
                string finalstr = "";
                for (int i = 0; i < num; i++)
                    finalstr += substr;
                // Finally push this to the stack
                st.push(finalstr);
            }
        }
        // Prepare ans
        while (!st.empty())
        {
            ans.insert(0, st.top());
            st.pop();
        }
        return ans;
    }
};
// @lc code=end
