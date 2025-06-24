impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        let n = arr.len();
        if n < 3 {
            return false;
        }

        let mut i = 0;

        // climb up
        while i + 1 < n && arr[i] < arr[i + 1] {
            i += 1;
        }

        // peak can't be first or last
        if i == 0 || i == n - 1 {
            return false;
        }

        // climb down
        while i + 1 < n && arr[i] > arr[i + 1] {
            i += 1;
        }

        i == n - 1
    }
}

