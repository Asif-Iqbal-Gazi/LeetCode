/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MinStack
{
public:
    /* Approach:
    1. Using Auxillary Stack -- T.C: O(1) for all operation, S.C: O(N)
    2. Using Vector Pair -- T.C: O(1) for all operation, S.C: O(N)
    */

    // Approach 2
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
            st.push_back({val, val});
        else
        {
            st.push_back({val, min(st.back().second, val)});
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }

    /* Approach 1
    MinStack()
    {
    }

    void push(int val)
    {
        if (ms.empty() || val <= as.top())
        {
            ms.push(val);
            as.push(val);
        }
        else
            ms.push(val);
    }

    void pop()
    {
        if (ms.top() == as.top())
        {
            as.pop();
            ms.pop();
        }
        else
            ms.pop();
    }

    int top()
    {
        return ms.top();
    }

    int getMin()
    {
        return as.top();
    }
    */

private:
    // Approach 2
    vector<pair<int, int>> st;

    /* Approach 1
    stack<int>
        ms;
    stack<int> as;
    */
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
