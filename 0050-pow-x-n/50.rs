impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        // Binary Exponentiation -- T.C: O(log N), S.C: O(1)
        let mut x = x;
        let mut N: i64 = n as i64;
        
        if n < 0 {
            N = -N;
            x = 1.0 / x;
        }

        let mut res: f64 = 1.0;
        while N > 0 {
            if N & 1 != 0 {
                res *= x;
            }
            x *= x;
            N = N / 2;
        }
        res
    }
}
