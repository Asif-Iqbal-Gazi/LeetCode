impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let (mut left, mut zero_count) = (0, 0);

        for &num in &nums {
            if num == 0 {
                zero_count += 1;
            }
            if zero_count > 1 {
                if nums[left] == 0 {
                    zero_count -= 1;
                }
                left += 1;
            }
        }
        (nums.len() - left) as i32
    }
}
