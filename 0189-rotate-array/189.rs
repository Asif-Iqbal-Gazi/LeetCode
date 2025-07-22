impl Solution {
    fn reverse(nums: &mut Vec<i32>, mut start: usize, mut end: usize) {
        while start < end {
            nums.swap(start, end);
            start += 1;
            end -= 1;
        }
    }
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
       let n = nums.len();
       let k = (k as usize) % n;
       if k == 0 {
           return;
       }

       Self::reverse(nums, 0, n - k - 1);
       Self::reverse(nums, n - k, n - 1);
       Self::reverse(nums, 0, n - 1);
    }
}
