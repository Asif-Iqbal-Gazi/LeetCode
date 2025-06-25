impl Solution {
    pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
        let mut curr = -1;
        let mut right_max = -1;
        let mut res = arr;
    
        for i in (0..res.len()).rev() {
            curr = res[i];
            res[i] = right_max;
             if curr > right_max {
                right_max = curr;
            }
        }
       res
    }
}
