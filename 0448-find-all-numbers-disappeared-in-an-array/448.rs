impl Solution {
    pub fn find_disappeared_numbers(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        for i in 0..n {
            let index = (nums[i].abs() - 1) as usize;
            if nums[index] > 0 {
                nums[index] = -nums[index];
            }
        }

        // let mut res = Vec::new();
        // for i in 0..nums.len() {
        //     if nums[i] > 0 {
        //         res.push((i + 1) as i32);
        //     }
        // }
        // res

        // More Rusty way ??
        (1..(n + 1) as i32)
            .filter(|&i| nums[i as usize - 1] > 0)
            .collect()
    }
}
