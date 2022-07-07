/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MyStack
{
    /* Approach:
        1. Using one queue
    */
public:
    MyStack()
    {
    }

    void push(int x)
    {
        // Idea is to push normally, then reverse
        q.push(x);
        int size = q.size();
        while (size > 1)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop()
    {
        int res = q.front();
        q.pop();
        return res;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
