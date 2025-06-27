impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let (mut left_sum, mut right_sum) : (i32, i32) = (0, nums.iter().sum());

        for (i, &num) in nums.iter().enumerate() {
            right_sum -= num;
            if left_sum == right_sum {
                return i as i32
            }
            left_sum += num;
        }
        -1
    }
}
