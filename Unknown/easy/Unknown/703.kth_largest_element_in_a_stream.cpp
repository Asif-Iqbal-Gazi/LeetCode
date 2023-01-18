/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest
{
private:
    int sz;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->sz = k;
        // Add in the insert elements into the minHeap
        for (auto x : nums)
            add(x);
    }

    int add(int val)
    {
        // If we have not crossed the size, push
        if (this->minHeap.size() < this->sz)
            this->minHeap.push(val);
        else
        { // We have passed the size, check if val is bigger
            if (this->minHeap.top() < val)
            {
                this->minHeap.pop();
                this->minHeap.push(val);
            }
        }

        return this->minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
