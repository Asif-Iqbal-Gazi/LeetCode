impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 3 {
            return n;
        }

        let (mut prev, mut prev2prev) = (2, 1);

        for _ in 3..=n {
            let curr = prev + prev2prev;
            prev2prev = prev;
            prev = curr;
        }
        prev
    }
}
