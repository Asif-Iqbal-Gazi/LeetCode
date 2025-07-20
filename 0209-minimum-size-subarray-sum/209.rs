impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let n = nums.len(); 
        let (mut left, mut running_sum) = (0, 0);

        let mut ans = n + 1;
        for right in 0..n {
            running_sum += nums[right];
            while running_sum >= target {
                ans = ans.min(right - left + 1);
                running_sum -= nums[left];
                left += 1;
            }
        }

        if ans == n + 1 {0} else {ans as i32}
    }
}
