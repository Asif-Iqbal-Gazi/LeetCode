impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let (n, m) = (mat.len(), mat[0].len());
        let mut res:Vec<i32> = vec![0; n * m];

        let (mut row, mut col) = (0, 0);
        for i in 0..(n * m) {
            res[i] = mat[row][col];

            if (row + col) % 2 == 0 {
                // Moving Up
                if col == m - 1 {
                    row += 1;
                } else if (row == 0) {
                    col += 1;
                } else {
                    row -= 1;
                    col += 1;
                }
            } else {
                // Moving Down
                if row == n - 1 {
                    col += 1;
                } else if col == 0 {
                    row += 1;
                } else {
                    row += 1;
                    col -= 1;
                }
            }
        }
        res
    }
}
