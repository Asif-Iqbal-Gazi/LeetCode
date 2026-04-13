class MovingAverage:
    def __init__(self, size: int):
        self.data = [0] * size
        self.tail = 0
        self.size = 0
        self.capacity = size
        self.sum = 0.0

    def next(self, val: int) -> float:
        self.sum -= self.data[self.tail]
        self.data[self.tail] = val
        self.sum += val
        self.tail = (self.tail + 1) % self.capacity
        if self.size < self.capacity:
            self.size += 1
        return self.sum / self.size


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
