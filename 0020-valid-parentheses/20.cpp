class Solution {
  public:
    bool isValid(string s) {
        /* Approach: Stack -- T.C: O(N), S.C: O(N) */

        // Optimization: Exit early
        if (s.size() % 2 == 1)
            return false;

        stack<char> st;
        for (char c : s) {
            switch (c) {
            case '(':
                st.push(')');
                break;
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            default:
                if (st.empty() || st.top() != c)
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};
