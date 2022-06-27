/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MyCircularQueue
{
    /*
    Approach : Using Circular Vector Container
        T.C: O(1) For all operation
    */
public:
    MyCircularQueue(int k)
    {
        size = 0;
        rear = k - 1;
        front = 0;
        capacity = k;
        queue.resize(k, -1);
    }

    bool enQueue(int value)
    {
        // Check if Full
        if (this->size == this->capacity)
            return false;
        this->rear = (this->rear + 1) % this->capacity;
        this->queue[rear] = value;
        this->size++;
        return true;
    }

    bool deQueue()
    {
        // Check if empty
        if (this->size == 0)
            return false;
        this->front = (this->front + 1) % this->capacity;
        this->size--;
        return true;
    }

    int Front()
    {
        // Check if empty
        if (this->size == 0)
            return -1;
        return this->queue[this->front];
    }

    int Rear()
    {
        // Check if empty
        if (this->size == 0)
            return -1;
        return this->queue[this->rear];
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }

private:
    int size, capacity, front, rear;
    vector<int> queue;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
