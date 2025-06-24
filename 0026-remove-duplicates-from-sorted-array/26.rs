impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut pos = 1;
        for i in 1..nums.len() {
            if nums[i] != nums[pos - 1] {
                nums[pos] = nums[i];
                pos += 1;
            }
        }
        pos as i32
    }
}
