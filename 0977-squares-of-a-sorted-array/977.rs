impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut result = vec![0; nums.len()];
        let (mut l, mut r) = (0, nums.len() - 1);
        let mut pos = nums.len() - 1;

        for pos in (0..nums.len()).rev() {
            let left_sq = nums[l] * nums[l];
            let right_sq = nums[r] * nums[r];
            if left_sq > right_sq {
                result[pos] = left_sq;
                l += 1;
            }
            else {
                result[pos]= right_sq;
                r -= 1;
            }
        }
        result;
    }
}
