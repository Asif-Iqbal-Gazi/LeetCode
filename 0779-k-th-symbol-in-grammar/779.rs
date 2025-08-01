impl Solution {
    pub fn kth_grammar(n: i32, k: i32) -> i32 {
        // Approach: Math
        let count = (k - 1).count_ones();
        if count % 2 == 0 {0} else {1}
    }
}
