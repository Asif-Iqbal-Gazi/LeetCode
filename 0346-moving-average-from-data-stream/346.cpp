#include <vector>
class MovingAverage {
  private:
    std::vector<int> data;
    int              tail;
    int              size;
    int              capacity;
    double           sum;

  public:
    MovingAverage(int size) : data(size, 0), tail(0), size(0), capacity(size), sum(0.0) {}

    double next(int val) {
        sum -= data[tail];
        data[tail] = val;
        sum += val;
        tail = (tail + 1) % capacity;
        if (size < capacity)
            size++;
        return sum / size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
