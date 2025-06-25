impl Solution {
    pub fn sort_array_by_parity(nums: Vec<i32>) -> Vec<i32> {
        let mut res = nums;
        let (mut l, mut r) = (0, res.len() -1);

        while l < r {
            if res[l] % 2 == 1 {
                res.swap(r, l);
                r -= 1;
            } else {
                l += 1;
            }
        }
        res
    }
}
