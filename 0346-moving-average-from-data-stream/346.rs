struct MovingAverage {
    data:       Vec<i32>,
    tail:       usize,
    size:       usize,
    capacity:   usize,
    sum:        f64,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MovingAverage {

    fn new(size: i32) -> Self {
        MovingAverage {
            data:       vec![0; size as usize],
            tail:       0,
            size:       0,
            capacity:   size as usize,
            sum:        0.0,
        }
    }
    
    fn next(&mut self, val: i32) -> f64 {
        self.sum                -= self.data[self.tail] as f64;
        self.data[self.tail]    = val;
        self.sum                += val as f64;
        self.tail               = (self.tail + 1) % self.capacity;
        if self.size < self.capacity {
            self.size += 1;
        }
        self.sum / self.size as f64 
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * let obj = MovingAverage::new(size);
 * let ret_1: f64 = obj.next(val);
 */
