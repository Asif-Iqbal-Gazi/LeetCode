use std::collections::HashSet;

impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut seen = HashSet::new();
        for &a in &arr {
            if seen.contains(&(2 * a)) || (a % 2 == 0 && seen.contains(&(a / 2))) {
                return true;
            }
            seen.insert(a);
        }
        false
    }
}

