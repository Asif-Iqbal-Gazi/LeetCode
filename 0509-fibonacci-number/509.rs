impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n <= 1 {
            return n;
        }        
        let (mut prev, mut prev2prev) = (1, 0);

        for _ in 2..=n{
            let curr = prev2prev + prev;
            prev2prev = prev;
            prev = curr;
        }
        prev
    }
}
