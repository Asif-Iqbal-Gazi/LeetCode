impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut count = [0; 101];

        for &h in &heights {
            count[h as usize] += 1;
        }

        let mut res = 0;
        let mut curr_height = 1;

        for &h in &heights {
            while count[curr_height] == 0 {
                curr_height += 1;
            }
            if h != curr_height as i32 {
                res += 1;
            }
            count[curr_height] -= 1;
        }
        res
    }
}
