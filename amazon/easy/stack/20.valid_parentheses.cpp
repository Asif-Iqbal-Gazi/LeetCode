/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
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
    bool isValid(string s)
    {
        /*
        Approach: Using Stack
        1. First check if there are even numbers of parenthesis, if not return false immediately
        2. Also, check if the first one is a closing parenthesis, if so return false immediately
        3. Inside a loop check if the char is a openning bracket, if so then push paired closing bracket in the stack.
        4. However, if it is a closing bracket, check the top of the stack, check if they are equal(Remember, we always push closing bracket)
        5. Finally, check if the set is empty
        */

        // Odd number of brackets, return false
        if (s.size() % 2 == 1)
            return false;

        // Check if the first one is a closing bracket, if so return false
        if (s[0] == ')' || s[0] == '}' || s[0] == ']')
            return false;

        stack<char> st;
        // The main loop
        for (char c : s)
        {
            if (c == '(')
                st.push(')');
            else if (c == '{')
                st.push('}');
            else if (c == '[')
                st.push(']');
            else
            {
                if (st.empty() || st.top() != c)
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end
