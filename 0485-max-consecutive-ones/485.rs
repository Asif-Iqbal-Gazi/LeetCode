use std::cmp::max;

impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let (mut res, mut curr_count) = (0, 0);
        for &num in &nums {
            if num == 1 {
                curr_count += 1;
                res = max(curr_count, res);
            } else {
                curr_count = 0;
            }
        }
        res
    }
}
